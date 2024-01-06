import yaml
import sys
import os
import struct
import math
import zlib
import oead
from colorama import init as colorama_init, Fore
from typing import Union, NoReturn
from enum import Enum

colorama_init()

# =====================================================================================================


class ETrackFlags(Enum):
    TRACK_NO_RETRO_NAME = 1 << 0


def pad_to_round_n(data, n, padding_byte=b'\x00'):
    remainder = len(data) % n
    if remainder == 0:
        return data
    else:
        padding_length = n - remainder
        return data.ljust(len(data) + padding_length, padding_byte)


def create_utf16be_str(text: str, length: int) -> bytes:
    return text.encode("utf-16be").ljust(length * 2, b"\0")


def create_ascii_str(text: str, length: int) -> bytes:
    return text.encode().ljust(length, b"\0")


def check_bflim(path: str, width: int, height: int, format: int) -> bool:
    try:
        img_h = open(path, "rb")
        img_h.seek(-0x28, os.SEEK_END)
        header = img_h.read(0x28)

        header_format = '>4sHHIIHH4sIHHHBBI'
        header_data = struct.unpack(header_format, header)

        img_h.close()

        if header_data[0] != b'FLIM':
            return False

        if header_data[1] != 0xFEFF:
            return False

        if header_data[2] != 0x14:
            return False

        if header_data[7] != b"imag":
            return False

        if header_data[9] != width:
            return False

        if header_data[10] != height:
            return False

        if header_data[12] != format:
            return False

        return True
    except Exception as e:
        print(e)
        return False


def issue_warning(msg: str, pause: bool = True):
    print(f"{Fore.YELLOW}[Warning] {msg}{Fore.RESET}")
    if pause:
        print("Press enter to continue...")
        input()


def issue_error(msg: str) -> NoReturn:
    print(f"{Fore.RED}[Error] {msg}{Fore.RESET}")
    sys.exit(1)


def get_yaml_file(path: str) -> Union[dict, None]:
    try:
        f = open(path, 'r', encoding="utf-8")
        return yaml.safe_load(f)
    except Exception as e:
        return None


YAMLEntry = Union[str, bool, int, list, dict]


def get_dict_entry(obj: dict[str, YAMLEntry],
                   key: str,
                   required: bool = False,
                   parent_key: str = None,
                   default: YAMLEntry = None,
                   check_type: type = None):

    res = obj.get(key, None)
    if res == None:
        if required:
            if parent_key:
                issue_error(f"Missing '{parent_key}.{key}' key from definition file")
            else:
                issue_error(f"Missing '{key}' key from definition file")
        else:
            return default

    if check_type and type(res) is not check_type:
        if parent_key:
            issue_error(f"'{parent_key}.{key}' must be of type '{check_type.__name__}'")
        else:
            issue_error(f"'{key}' must be of type '{check_type.__name__}'")

    return res

# =====================================================================================================


if len(sys.argv) < 2:
    issue_error("Usage -> python ctdef_builder.py <ctdef.yaml>")

ctdef_filename = sys.argv[1]
ctdef = get_yaml_file(ctdef_filename)
if not ctdef:
    issue_error("Failed to load ctdef.yaml, file not found or invalid (UTF-8 encoding may be required)")

supported_version_major = [1]
supported_version_minor = {
    1: [0]
}

file_settings = get_dict_entry(ctdef, "file", required=True, check_type=dict)
distribution_settings = get_dict_entry(ctdef, "distribution", required=True, check_type=dict)

file_ver_major = get_dict_entry(file_settings, "ctdef_version_major", required=True, check_type=int)
file_ver_minor = get_dict_entry(file_settings, "ctdef_version_minor", required=True, check_type=int)

if file_ver_major not in supported_version_major:
    issue_error(f"This builder doesn't support the specified major version -> {file_ver_major}")

if file_ver_minor not in supported_version_minor[file_ver_major]:
    issue_error(f"This builder doesn't support the specified minor version -> {file_ver_minor}")

# =====================================================================================================

distrib_name = get_dict_entry(distribution_settings, "name", parent_key="distribution", required=True, check_type=str)
distrib_version = get_dict_entry(distribution_settings, "version", parent_key="distribution", required=True, check_type=str)
distrib_author = get_dict_entry(distribution_settings, "author", parent_key="distribution", required=True, check_type=str)
distrib_description = get_dict_entry(distribution_settings, "description", parent_key="distribution", check_type=str)

archive_dir = get_dict_entry(distribution_settings, "archive_dir", parent_key="distribution", default="ctgp.szs", check_type=str)
content_dir = get_dict_entry(distribution_settings, "content_dir", parent_key="distribution", default="content", check_type=str)
features = get_dict_entry(distribution_settings, "features", default={}, check_type=dict)

tracks = get_dict_entry(distribution_settings, "tracks", parent_key="distribution", required=True, check_type=list)
cups = get_dict_entry(distribution_settings, "cups", parent_key="distribution", required=True, check_type=list)
battle_tracks = get_dict_entry(distribution_settings, "battle_tracks", parent_key="distribution", default=[], check_type=list)

if len(distrib_name) >= 48:
    issue_error("Distribution name is too long, it must be less than 48 characters")

if len(distrib_version) >= 16:
    issue_error("Distribution version is too long, it must be less than 16 characters")

if len(distrib_author) >= 96:
    issue_error("Distribution author is too long, it must be less than 96 characters")

if len(distrib_description) >= 512:
    issue_error("Distribution description is too long, it must be less than 512 characters")

num_tracks = len(tracks)
num_cups = len(cups)
num_bt_tracks = len(battle_tracks)

if num_tracks == 0:
    issue_error("There are no tracks defined")

if num_cups != math.ceil(num_tracks / 4):
    issue_error("The number of cups must be equal to the value of: ceil(number of tracks / 4)")


archive_dir = os.path.abspath(
    os.path.join(
        os.path.dirname(os.path.abspath(ctdef_filename)),
        os.path.normpath(archive_dir)
    ))

content_dir = os.path.abspath(
    os.path.join(
        os.path.dirname(ctdef_filename),
        os.path.normpath(content_dir)
    ))

if not os.path.isdir(archive_dir):
    issue_error(f"Archive directory doesn't exist -> {archive_dir}")

if not os.path.isdir(content_dir):
    issue_error(f"Content directory doesn't exist -> {content_dir}")
# =====================================================================================================


def print_value(name: str, value):
    print(f"{name}: {Fore.GREEN}{value}{Fore.RESET}")


print()
print("======================== CTDEF Builder ========================")
print_value("Name", distrib_name)
print_value("Version", distrib_version)
print_value("Author", distrib_author)
print_value("Description", distrib_description.rstrip())
print()
print_value("Number of tracks", f"{num_tracks} (across {num_cups} cup{'' if num_cups == 1 else 's'})")
print_value("Number of battle tracks", f"{num_bt_tracks}")
print()
print_value("Using archive directory (absolute)", archive_dir)
print_value("Using content directory (absolute)", content_dir)
print("===============================================================")
print()

# =====================================================================================================

current_cup = 0
output_cups = []

if os.path.isdir(os.path.join(content_dir, "mapobj")):
    issue_warning("The 'mapobj' directory exists in the content directory, make sure to not replace the original files.", pause=False)
    issue_warning("CTGP-Café allows the use of custom mapobj files. See the documentation for more information.")

for i in range(num_cups):
    parent_key = f"cups[{i}]"

    name = get_dict_entry(cups[i], "name", parent_key=parent_key, required=True, check_type=str)
    icon = get_dict_entry(cups[i], "icon", parent_key=parent_key, required=True, check_type=str)

    if len(name) >= 16:
        issue_error(f"Cup name is too long, it must be less than 16 characters")

    if len(icon) >= 48:
        issue_error(f"Cup icon path is too long, it must be less than 48 characters")

    if not os.path.isfile(os.path.join(content_dir, icon)):
        issue_error(f"Cup icon doesn't exist -> {os.path.join(content_dir, icon)}")

    if not check_bflim(os.path.join(content_dir, icon), 200, 200, 5):
        issue_error(f"Cup icon is not a valid BFLIM image (must be 200x200 B5G6R5_UNORM) -> {os.path.join(content_dir, icon)}")

    output_cups.append({
        "name": name,
        "icon": icon,
        "tracks": []
    })

for i in range(num_tracks):

    cup_idx = i // 4
    if (i % 4 == 0) or i == 0:
        print(f"Cup {cup_idx + 1} - {cups[cup_idx]['name']}")

    parent_key = f"tracks[{i}]"
    retro_name = get_dict_entry(tracks[i], "retro_name", parent_key=parent_key, check_type=str)
    name = get_dict_entry(tracks[i], "name", parent_key=parent_key, required=True, check_type=str)
    author = get_dict_entry(tracks[i], "author", parent_key=parent_key, required=True, check_type=str)
    directory = get_dict_entry(tracks[i], "directory", parent_key=parent_key, required=True, check_type=str)
    track_pic = get_dict_entry(tracks[i], "track_pic", parent_key=parent_key, default=f"{directory}/track_pic.bflim", check_type=str)

    track_flags = 0

    if retro_name and len(retro_name) >= 6:
        issue_error(f"Retro track name is too long, it must be less than 6 characters")

    if len(name) >= 20:
        issue_error(f"Track name is too long, it must be less than 20 characters")

    if len(author) >= 20:
        issue_error(f"Track author is too long, it must be less than 20 characters")

    if len(directory) >= 32:
        issue_error(f"Track directory is too long, it must be less than 32 characters")

    if len(track_pic) >= 48:
        issue_error(f"Track picture path is too long, it must be less than 48 characters")

    if not os.path.isdir(os.path.join(content_dir, f"course/{directory}")):
        issue_error(f"Track directory doesn't exist -> {os.path.join(content_dir, directory)}")

    if not os.path.isfile(os.path.join(content_dir, f"course/{track_pic}")):
        issue_error(f"Track picture doesn't exist -> {os.path.join(content_dir, track_pic)}")

    if not check_bflim(os.path.join(content_dir, f"course/{track_pic}"), 304, 256, 0x17):
        issue_error(f"Track picture is not a valid BFLIM image (must be 304x256 BC3_UNORM_SRGB) -> {os.path.join(content_dir, track_pic)}")

    track_full_name = (retro_name + " " if retro_name else "") + name
    print(f"Track {i + 1}: {Fore.GREEN}{track_full_name}{Fore.RESET} ({directory}) by {Fore.CYAN}{author}{Fore.RESET}")

    if not retro_name:
        track_flags |= ETrackFlags.TRACK_NO_RETRO_NAME.value

    output_cups[cup_idx]["tracks"].append({
        "retro_name": retro_name,
        "name": name,
        "author": author,
        "directory": directory,
        "track_pic": track_pic,
        "track_flags": track_flags
    })

print()
print("===============================================================")
print()
try:

    ctdef_filepath = os.path.join(archive_dir, "ctdef.bin")

    # Write CTINFO header
    output_ctinfo = b"CTIF"
    output_ctinfo += create_utf16be_str(distrib_name, 48)
    output_ctinfo += create_utf16be_str(distrib_version, 16)
    output_ctinfo += create_utf16be_str(distrib_author, 96)
    output_ctinfo += create_utf16be_str(distrib_description, 512)

    # Write CUP0 header
    output_cup0 = b"CUP0"
    output_cup0 += struct.pack(">I", num_cups)

    for cup in output_cups:
        output_cup0 += create_utf16be_str(cup["name"], 16)
        output_cup0 += create_ascii_str(cup["icon"], 48)
        output_cup0 += struct.pack(">I", len(cup["tracks"]))

        for track in cup["tracks"]:
            output_cup0 += struct.pack(">I", track["track_flags"])
            output_cup0 += create_utf16be_str(track["retro_name"] if track["retro_name"] else "", 6)
            output_cup0 += create_utf16be_str(track["name"], 20)
            output_cup0 += create_utf16be_str(track["author"], 20)
            output_cup0 += create_ascii_str(track["directory"], 32)
            output_cup0 += create_ascii_str(track["track_pic"], 48)
            output_cup0 = pad_to_round_n(output_cup0, 4)

    # Write CTDEF header
    output_ctdef = b"CTDF"
    output_ctdef += struct.pack(">HH", file_ver_major, file_ver_minor)
    output_ctdef = output_ctdef.ljust(0x20, b"\0")

    # Write output file

    output_file = b""
    output_file += output_ctdef
    output_file += output_ctinfo
    output_file += output_cup0

    compressed_output = zlib.compress(output_file, level=9)

    with open(ctdef_filepath, "wb") as f:
        f.write(compressed_output)

except Exception as e:
    issue_error(f"ctdef.bin: Failed building -> {e}")

print_value("ctdef.bin", f"built successfully! ({os.path.abspath(ctdef_filepath)})")

# =====================================================================================================

output_sarc = oead.SarcWriter(oead.Endianness.Big)
for root, dirs, files in os.walk(archive_dir):
    for file in files:
        relative_path = os.path.relpath(os.path.join(root, file), archive_dir).replace("\\", "/")
        with open(os.path.join(root, file), "rb") as f:
            output_sarc.files[relative_path] = f.read()

with open(os.path.join(content_dir, "ctgp.szs"), "wb") as f:
    file_data = bytes(output_sarc.write()[1])
    f.write(oead.yaz0.compress(file_data))
