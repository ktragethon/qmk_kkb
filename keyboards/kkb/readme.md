# KKB (Keychron K7 Pro ISO) - QMK Firmware

![Keychron K7 Pro ISO](https://i.imgur.com/fjMLs4h.jpeg)

* Keyboard Maintainer: [ktragethon](https://github.com/ktragethon/)
* Hardware Supported: Keychron K7 Pro ISO (wired only)
* Hardware Availability: [Keychron K7 Pro ISO](https://www.keychron.com/products/keychron-k7-pro-qmk-via-wireless-custom-mechanical-keyboard-iso-layout-collection)

---

## Legal Disclaimer

> **⚠️ IMPORTANT:** **This is unofficial third-party firmware** - not affiliated with or endorsed by Keychron.

**USE AT YOUR OWN RISK**

This firmware is provided "AS IS" under the GPL-2.0-or-later license, WITHOUT WARRANTY OF ANY KIND, express or implied. The author(s) shall not be liable for any damages, including but not limited to:

- Hardware damage or "bricking" of your keyboard
- Loss of original firmware or functionality
- Voiding of manufacturer warranty
- Any other direct, indirect, incidental, or consequential damages

**By flashing this firmware, you acknowledge that:**
- You understand the risks involved in modifying keyboard firmware
- You accept full responsibility for any consequences
- You waive any claims against the author(s) for damages or losses
- This is an unofficial, community-created firmware not endorsed by Keychron

For full license terms, see [GPL-2.0-or-later](https://spdx.org/licenses/GPL-2.0-or-later.html).


## **IMPORTANT: Read Before Flashing**

**This firmware completely replaces Keychron's factory firmware and is NOT compatible with:**
- VIA configurator (web or desktop app)
- Keychron's web configuration tools
- Any Keychron-specific features
- Wireless/Bluetooth functionality
- Battery operation

**Flashing this firmware will:**
- Replace the original firmware (you should make a backup if possible)
- Require QMK Toolbox or command-line tools for future updates
- Potentially void your warranty
- Depending on keymap, might enable LED brightness above factory-tested values
- Convert your keyboard to **wired-only operation**

**This is a custom implementation built on QMK, not a modification of Keychron's QMK fork.**

---

## Features & Modifications

### What's Different from Stock Keychron K7 Pro:

**Removed:**
- Bluetooth/wireless support (radio disabled in firmware)
- Battery functionality
  - Battery may be left installed (not tested)
- VIA support (use QMK directly instead)
- RGB animations (disabled to save firmware space, but can be re-enabled in [keyboard.json](keyboard.json))
- Keychron's factory keymaps and macros

**Custom Implementation:**
- Custom matrix scanning
- Intended for wired-only use

### Battery Status:
- **Battery switch has no function** in this firmware
- Battery can be removed if desired (voids warranty)
- Bluetooth radio is disabled in firmware

---

## Compiling & Flashing

### Build Command:
```sh
qmk compile -kb kkb -km default
```
or
```sh
make kkb:default
```

## Bootloader

First time flash
- Follow Keychrons instructions for putting the keyboard in bootloader

Subsequent flashing
- Hold key at position (0,0), usually `ESC` while connecting (booting) the keyboard

*Some keymaps include layer with keycode `QK_BOOT` that enables putting the keyboard into bootloader without unplugging it*

---

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
