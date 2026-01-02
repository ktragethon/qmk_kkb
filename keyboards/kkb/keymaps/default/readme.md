# KKB - __'default'__ Keymap

![Keychron K7 Pro ISO](https://i.imgur.com/fjMLs4h.jpeg)

* Keyboard Maintainer: [ktragethon](https://github.com/ktragethon/)
* Hardware Supported: Keychron K7 Pro ISO
* Hardware Availability: [Keychron K7 Pro ISO](https://www.keychron.com/products/keychron-k7-pro-qmk-via-wireless-custom-mechanical-keyboard-iso-layout-collection)

## Notes

**This is custom firmware. See [main readme](../../readme.md) for important warnings and legal disclaimer.**

Standard Windows keymap with built-in RGB effects and media controls. Uses QMK's RGB matrix system for lighting effects (if enabled in [keyboard.json](../../keyboard.json)). This keymap is similar to the original Keychron K7 Pro ISO firmware, except it's probably for Windows only (should be easily convertable to MAC in [keymap.c](keymap.c)).

## Key Features

### **Standard RGB Matrix Support**
* Built-in QMK RGB effects*
* Standard RGB controls (toggle, mode switching, brightness, hue, saturation, speed)*
* Uses QMK defaults*

*___Requires enabling the RGB effects in [keyboard.json](../../keyboard.json)___

### **Media Controls**
* Media playback control
* Volume adjustment
* Screen brightness control (if supported by OS)

## Quick Start

### Base Layers (DIP Switch)
* **Position 0 (`WIN_STANDARD`)**: Standard Windows, FN1 and FN2 access
  * *FN1: RGB controls and Media controls*
  * *FN2: Function keys F1-F12*
* **Position 1 (`WIN_SPECIAL`)**: Standard Windows, SPC and FN2 access
  * *SPC: RGB controls and Media controls*
  * *FN2: Function keys F1-F12*

*As a starting point, modify the keys in the `SPC` keymap, to be able to switch with the standard layout and your custom keymap at any time by simply using the Base-layer DIP at the back of your keyboard*

See [keymap.c](keymap.c) for complete layer definitions.

### RGB Controls (FN1 Layer)

**Top Row:**
* **2**: Brightness down
* **3**: Brightness up
* **5**: RGB brightness down
* **6**: RGB brightness up
* **7-9**: Media previous/play/next
* **0/-/=**: Volume mute/down/up

**Home Row (Left Side):**
* **CAPS**: RGB toggle on/off
* **A**: Next RGB effect
* **S**: RGB brightness up
* **D**: Hue increase
* **F**: Saturation increase
* **G**: Speed increase

**Second Row (Left Side):**
* **Z**: Previous RGB effect
* **X**: RGB brightness down
* **C**: RGB brightness down (duplicate)
* **V**: Hue decrease
* **B**: Saturation decrease
* **N**: N-Key Rollover toggle

## RGB Feedback

This keymap uses QMK's built-in RGB matrix effects. Available effects depend on what's enabled in [keyboard.json](../../keyboard.json). No custom layer colors or indicators.

## Configuration

RGB effects can be enabled/disabled in [keyboard.json](../../keyboard.json) by setting animations to `true` or `false`:
```json
"rgb_matrix": {
    "animations": {
        "solid_color": true,
        "breathing": true,
        // ... etc
    }
}
```
