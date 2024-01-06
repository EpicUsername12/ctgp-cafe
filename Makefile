# This is a minimal set of ANSI/VT100 color codes
_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

# Colors
_GREY=\033[30m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_PURPLE=\033[35m
_CYAN=\033[36m
_WHITE=\033[37m

.DEFAULT_GOAL := all

PROJECT_NAME := CTGP-Cafe

GAME_NAME := Mario Kart 8
GAME_VERSION := v81 (4.2)
GAME_TITLE_ID_PATH := 0005000e/1010ed00
# This is the input original RPX file that you need to add yourself from the game update
RPX_DIRECTORY := ./project/rpxs
RPX_FILENAME := Turbo.rpx
RPX_SHA1_HASH := 8e89e70f9e99d94013697a3bc66964ce273fbb64

# This may need to be changed to your CEMU path if you want to use "make install"
CEMU_PATH := G:/WiiU/Games/DATA/EMULATORS/Cemu/BIN
GAME_UPDATE_PATH := $(CEMU_PATH)/mlc01/usr/title/$(GAME_TITLE_ID_PATH)/code

OUTPUT_RPX_PATH := ./project/out/Emulator/$(PROJECT_NAME)/$(RPX_FILENAME)
LAST_MODIFIED_TIMESTAMP := $(shell stat -c %Y $(OUTPUT_RPX_PATH))
LOCALIZED_DATE_TIME := $(shell date -d @$(LAST_MODIFIED_TIMESTAMP) "+%Y-%m-%d %H:%M:%S")

# Check if the file exists and matches the SHA-1 hash
ifeq (,$(wildcard $(RPX_DIRECTORY)/$(RPX_FILENAME)))
$(error File $(RPX_DIRECTORY)/$(RPX_FILENAME) does not exist, you need to add the file yourself from the game update)
else
FILE_HASH := $(shell sha1sum $(RPX_DIRECTORY)/$(RPX_FILENAME) | cut -d ' ' -f 1)
ifneq ($(FILE_HASH),$(RPX_SHA1_HASH))
$(error File $(RPX_DIRECTORY)/$(RPX_FILENAME) exists, but its SHA-1 hash does not match (expected: $(RPX_SHA1_HASH), actual: $(FILE_HASH)))
endif
endif

# Default target
all:
	@echo -e "${_BLUE}Building $(PROJECT_NAME) for $(GAME_NAME) $(GAME_VERSION)${_END}"
	@python ./CLPC/src/main.py ./project/project.yaml

# Install target
install: check_cemu
	@echo -e "${_BLUE}Moving built RPX $(RPX_FILENAME) (built on: $(LOCALIZED_DATE_TIME)) to CEMU${_END} ($(CEMU_PATH))"
	@cp $(OUTPUT_RPX_PATH) $(GAME_UPDATE_PATH)/$(RPX_FILENAME)

clean:
	@echo -e "${_BLUE}Cleaning build files...${_END}"
	@rm -rf ./project/out ./project/temp ./project/rpxs/$(subst .rpx,.elf,$(RPX_FILENAME))

check_cemu:
ifeq ($(CEMU_PATH),)
    $(error CEMU_PATH must be set in the Makefile (at the top))
endif
ifeq ($(wildcard $(GAME_UPDATE_PATH)),)
	$(error CEMU $(GAME_NAME) update directory was not found. ($(GAME_UPDATE_PATH)/) - please check CEMU_PATH in the Makefile)
endif

.PHONY: all install