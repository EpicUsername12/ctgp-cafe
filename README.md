# CTGP-Cafe

CTGP-Cafe code and tools to help build CT distributions and reverse-engineer the game

This project aims to provide utilities and features for Mario Kart 8 modders, such as course extensions, UI changes, mapobj extensions (to avoid replacement) as well as the ability to easily create distributions and share them. (and much more)

---

# Table of contents

- [Features list](#features-list)
- [Usage instructions](#usage-instructions)
- [Build instructions](#build-instructions)
  - [Recommended VSCode settings](#recommended-vscode-settings)

---

# Features list

- Coming soon ...

---

# Usage instructions

- Coming soon ...

---

# Build instructions

- Clone the repo

```shell
git clone --recursive https://github.com/EpicUsername12/ctgp-cafe.git
```

- Put the original update file `/code/Turbo.rpx` (any region | **v81**, known as **v4.2**) in `./project/rpxs`
- Set your `GHS_ROOT` environment variable to your `GHS Multi 5.3.27` installation (example: `C:\ghs\multi5327`)
- Set your `CLPC_WIIURPXTOOL_PATH` environment variable to your [wiiurpxtool.exe](https://www.github.com/) file
  - This must be the absolute path to the `.exe`

or

- Manually change the path of `wiiurpxtool` and `GHS` in [the CLPC main file](./CLPC/src/main.py#L20-21)

---

- Then you can run these commands to build the files

```shell
make # Builds the project
make install # Moves the built RPX to your CEMU folder
```

- `make install` requires you to change the `CEMU_PATH` in the **Makefile**
  - It must be the directory of your CEMU installation (where the `/mlc01` folder is)

### Recommended VSCode settings

- Intellisense C++ extension
- And this `c_cpp_properties.json` file

```json
{
  "configurations": [
    {
      "name": "PowerPC GHS",
      "includePath": ["${workspaceFolder}/**"],
      "defines": [
        "_DEBUG",
        "UNICODE",
        "_UNICODE",
        "PLATFORM_IS_EMULATOR",
        "__VS_CODE__",
        "cafe"
      ],
      "windowsSdkVersion": "10.0.22000.0",
      "compilerPath": "C:/devkitPro/devkitPPC/bin/powerpc-eabi-gcc.exe",
      "cStandard": "gnu89",
      "cppStandard": "c++03",
      "intelliSenseMode": "gcc-x86"
    }
  ],
  "version": 4
}
```

I have zero warnings and issues using these settings.

---
