# KKB - __'code1'__ keymap

![Keychron K7 Pro ISO](https://i.imgur.com/fjMLs4h.jpeg)

* Keyboard Maintainer: [ktragethon](https://github.com/ktragethon/)
* Hardware Supported: Keychron K7 Pro ISO
* Hardware Availability: [Keychron K7 Pro ISO](https://www.keychron.com/products/keychron-k7-pro-qmk-via-wireless-custom-mechanical-keyboard-iso-layout-collection)

## Notes

**This is custom firmware. See [main readme](../../readme.md) for important warnings and legal disclaimer.**

**LED Brightness:** This keymap uses M_TV = 0x38 (8.75mA per channel) instead of the stock K7 Pro ISO default 0x18 (3.75mA). This value matches Keychron's ANSI K7 Pro firmware. Use at your own risk.
*See [config.h](config.h) for details*

Coding-focused custom keymap with intelligent RGB feedback, and persistent brightness control. All lighting is firmware-controlled (no dynamic effects) for maximum customization and minimal flash usage.

## Key Features

### **Custom RGB System**
* Firmware-defined layer colors (no built-in effects)
* Per-key highlighting for active function keys
* Visual brightness indicator on number row (when in config)
* Automatic Caps Lock indication
* Optimized for coding workflow visibility

### **Multi-Language Bracket Support**
Compile-time language selection for proper characters in layers:
* **Norwegian layout**
* **US layout**

Configure in [keymap_aliases.h](keymap_aliases.h):
```c
#define HOST_LAYOUT_NORWEGIAN 1         // Default
// #define HOST_LAYOUT_US 1             // Alternative
```

## Quick Start

### Base Layers (DIP Switch selectable)
* **Position 0 (`BASE`)**: Standard Windows layout (same as default keymap)
  * **FN1**: Media controls
  * **FN2:** F1-F12
* **Position 1 (`CODE`)**: Coding layout with extended function layers

**See [keymap.c](keymap.c) for complete layer definitions**


## Details for the CODE Base-layer (DIP Position 1)

### Layers

* **`CODE`**: Coding layout with extended function layers
  * **FN1**: `[]` `()` `{}` `<>` `&` `|` `=`
  * **FN2**: `!` `?` `+` `-` `*` `/` `"` `'` `;` `:` 
  * **CAPS**: F1-F12 + Custom key-combos
  * **NUBS**: Navigation + Custom key-combos
    * **ESC**: Pressing `ESC` when in Navigation layer enters `SYSTEM` layer

### SYSTEM Layer

***The SYSTEM layer can be accessed by pressing `ESC` while holding `NUBS`***

#### Enable / Disable CAPS-Lock
1. Use **CAPS** key to toggle CAPS-Lock

#### Brightness Control
1. Use **Arrow UP/DOWN** to adjust brightness
   * *Number 1-0 show brightness*
2. Press **HOME** to exit

#### Bootloader mode
1. While in `SYSTEM` Layer Hold **Spacebar** and press **ENTER** to enter bootloader mode
    * *Note: To exit bootloader either flash, or reboot, the keyboard*

## RGB Feedback

**Base Layer Colors:**
* **Gold**: Standard Windows layout (Position 0)
* **Blue**: Code layout (Position 1)

**Function Layer Indicators:**
* **Green**: Active/available keys when layer(s) activated
* **Cyan**: Brightness level (number row 1-0), in layer System Config
* **Orange**: Caps Lock active (overrides base color when Caps active)

**System Layer:**
* **White**: Bootloader access

### Language Support
To make it easier to use different system-languages with the keyboard-firmware, an abstraction for custom keycodes or keys that are language-dependent for layers has been added [keymap_aliases.h](keymap_aliases.h). This makes the `keymap.c` file language agnostic, while changing the language or adding new languages is straight-forward. Although, still compile-time dependent.

For the keyboard to send specific characters that might differ depending on system-language, please update sections in [keymap_aliases.h](keymap_aliases.h) accordingly, with new layouts and new flags if you wish to add languages.

At the moment Norwegian and English (US) is supported, simply change the flag defined in [keymap_aliases.h](keymap_aliases.h): `HOST_LAYOUT_NORWEGIAN` or `HOST_LAYOUT_US`
