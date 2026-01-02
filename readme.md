# KKB - QMK-based firmware for Keychron K7 Pro ISO

[![License: GPL v2+](https://img.shields.io/badge/License-GPL%20v2+-blue.svg)](LICENSE)
[![QMK](https://img.shields.io/badge/Powered%20by-QMK-blue)](https://qmk.fm/)
[![Build KKB Firmware](https://github.com/ktragethon/qmk_kkb/actions/workflows/main.yml/badge.svg)](https://github.com/ktragethon/qmk_kkb/actions/workflows/main.yml)
[![ASCII Keymaps](https://img.shields.io/badge/Docs-GitHub%20Pages-blue)](https://ktragethon.github.io/qmk_kkb/)

Custom firmware based on QMK, for the Keychron K7 Pro ISO (69-key) keyboard.

> **⚠️ IMPORTANT:** **This is unofficial third-party firmware** - not affiliated with or endorsed by Keychron or QMK.

- **Use at your own risk** - Custom firmware can brick your keyboard
- **Voids warranty** - Especially with hardware modifications or custom LED Brightness
- **Requires technical knowledge** - You should understand QMK basics
- **No warranty provided** - Provided "as-is" under GPL-2.0-or-later
- **No pre-built binaries** - You must build and customize yourself


**➡️ [Read complete keyboard documentation (warnings, specs, features, instructions)](keyboards/kkb/readme.md)**

This includes:
- Important warnings and legal disclaimer
- Hardware specifications and modifications
- Features and functionality
- Build and flash instructions

---

## Built With

This firmware is based on **[QMK Firmware](https://qmk.fm/)** (GPL-2.0-or-later).

- **QMK Repository:** [github.com/qmk/qmk_firmware](https://github.com/qmk/qmk_firmware)
- **QMK Documentation:** [docs.qmk.fm](https://docs.qmk.fm/)

---

## Why This Firmware?

**Short answer:** True mainline QMK with no wireless, no battery, and full customization.

**What makes it different from stock Keychron K7 Pro ISO firmware:**

| Feature | Keychron K7 Pro ISO Firmware | This Firmware |
|---------|-------------------|---------------|
| **QMK Version** | Modified fork | Mainline QMK |
| **Updates** | Unknown | Users choice (submodule) |
| **Wireless** | Bluetooth + Battery | Disabled (wired-only) |
| **Customization** | Fork | QMK |
| **VIA Support** | Yes | No |

**Built for users who:**
- ✅ Want **real QMK**, not a fork
- ✅ Prefer **wired-only** keyboards (no battery concerns)
- ✅ Need **full customization** beyond what VIA offers
- ✅ Want to learn firmware development
- ✅ Are comfortable building and flashing firmware

**Not for users who:**
- ❌ Want Bluetooth/wireless functionality
- ❌ Need VIA/configurator support
- ❌ Want plug-and-play pre-built firmware
- ❌ Aren't comfortable with command-line tools

---

## About This Project

### Personal journey

As I wanted to have a fully customizable keyboard, with support for multiple layers and preferably control over the LEDs I started using QMK keyboards some time ago. I didn't want to build my physical keyboard, so I purchased manufactured keyboards with QMK (and/or VIA support). Finding standard height keyboards with QMK support was straightforward.

However, I wanted a ~65% low-profile ISO keyboard with LEDs, built on QMK, but this turned out to be more difficult to find. I landed on purchasing a Keychron K7 PRO ISO, but the manufacturer firmware for this keyboard is a fork of QMKs repo that differs quite a lot from QMK. In essence, the manufacturer standard firmware did not provide me with enough flexibility for what I wanted to achieve. I could either modify the Keychron fork, or build on top of standard QMK - I chose to build on top of QMK.

In addition, and this was a major issue for me, the keyboard natively supports bluetooth and has a battery. I do not want any of those.

### Hardware-mods

Personally, I have disassembled and removed the battery from my keyboard (***Voids warranty***), as I do not want any battery-packs inside my keyboard. The Bluetooth-radio is non-functional, but I have not disassembled or physically made changes to remove it - this has been done in firmware only.

### QMK, Firmware and Configuration

I used the main repo from QMK and created my own custom keyboard using the template. The `keyboards/kkb` is aiming to be QMK compliant, to take advantage of future updates of the QMK-Core and to make use of the fantastic functionality that QMK already provides!

My specific keyboard layout do not exist in the toolboxes or tools provided by QMK, and for me this isn't really necessary, so at the moment there is no support for using e.g. QMKs configurator or similar for making keymaps. This firmware uses hard-coded keymaps, that are flashed to the keyboard.

### Artifacts

Due to the lack of configuration tools, I do not have pre-built artifacts for you to flash directly, I expect anyone who wants to test and/or use this firmware to clone and build it yourself.

**ASCII keymap visualizations** are automatically generated and published to GitHub Pages:
- **[View Keymaps](https://ktragethon.github.io/qmk_kkb/)**

These visualizations show all available keymaps in multiple language layouts.

### Contributions

As the keyboard ***layouts*** are highly personal I would encourage anyone to make their own layouts and customizations. If you find issues or have suggestions to the general code, feel free to post them here:
- **[Issues](https://github.com/ktragethon/qmk_kkb/issues)**

*Please note however that this is a hobby project of mine, I'll respond at my own pace.*

---

## Quick Start (Repository Setup)

### Prerequisites

- **[QMK CLI](https://docs.qmk.fm/#/newbs_getting_started)** installed
- Git with submodule support
- Basic QMK knowledge

### Repository Setup

```bash
# 1. Clone repository with QMK submodule
git clone --recurse-submodules https://github.com/ktragethon/qmk_kkb.git
cd qmk_kkb

# 2. Add the keyboards/kkb to the exclude-list (avoid git reporting untracked content)
echo "keyboards/kkb" >> .git/modules/qmk_firmware/info/exclude

# 3. Create keyboard symlink (required for QMK to find the keyboard)
ln -s $(pwd)/keyboards/kkb qmk_firmware/keyboards/kkb

# 4. Verify setup (Should show symlink to ../../keyboards/kkb)
ls -l qmk_firmware/keyboards/kkb
```

### Building and Flashing

**Now that the repository is set up, see the keyboard documentation for build and flash instructions:**

**[keyboards/kkb/readme.md](keyboards/kkb/readme.md)**:
- Hardware specifications and modifications
- Build commands (`qmk compile`)
- Flash instructions (`qmk flash`)
- Bootloader information
- Feature details

**Keymaps:**
- See [**keyboards/kkb/keymaps/**](keyboards/kkb/keymaps/)

### Optional: Generate ASCII Visualizations Locally

You can generate ASCII keymap visualizations locally for development purposes, or as a guidance.

See the [tools readme](tools/readme.md) for instructions.

### Optional: Intellisense and Others

#### Create compilation database and symlink to compile_commands.json

```bash
# Generate compilation database for IntelliSense
cd qmk_firmware
qmk generate-compilation-database -kb kkb -km default
cd ..

# Create symlink
ln -sf qmk_firmware/compile_commands.json compile_commands.json
```

***Note: You may need to reload your editor at this point***

#### If clang symlinks are broken, recreate

```bash
# From repository root
ln -sf qmk_firmware/.clangd .clangd
ln -sf qmk_firmware/.clang-format .clang-format
```

#### If (VSCode) settings is broken, recreate

```bash
# From repository root
mkdir -p .vscode
cp qmk_firmware/.vscode/settings.json .vscode/settings.json
sed -i 's|"\./data/schemas/|"./qmk_firmware/data/schemas/|g' .vscode/settings.json
```

---

## Acknowledgments

- **[QMK Firmware](https://github.com/qmk/qmk_firmware)** - The foundation of this project
- **[QMK Community](https://qmk.fm/)** - Documentation and support
- **Keychron** - Hardware manufacturer (K7 Pro)

---

**Keychron® is a registered trademark of Keychron, Inc.** This project is not affiliated with, endorsed by, or supported by Keychron.

---

## License

Licensed under **GPL-2.0-or-later** (same as QMK Firmware).

- ✅ Free to use, modify, distribute
- ✅ Source code must remain open
- ✅ Derivative works must use GPL-2.0+

See [LICENSE](LICENSE) for details.