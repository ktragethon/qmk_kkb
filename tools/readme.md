# ASCII Keymap Visualization Generator

Scripts to generate ASCII visualizations of available keymap layouts. This is a simple development tool with hardcoded paths and variables specific to this project. These scripts have been largely auto-generated and is intended as a quick development aid.

* [Master-branch layouts](https://ktragethon.github.io/qmk_kkb/)

---

## What these scripts do

There are three scripts
- `asciimap_single.py` - Generates text-file based on a single keymap
- `asciimaps_all.py` - Generates text-files for all keymaps
- `prepare_site_md.py` - Generates text- and md-files for all keymaps

The scripts replace QMK-names and/or custom names for keys, combos, language-specifics etc. It gathers the layouts from the keymaps in `kkb` (or in the _single version you can specify folder), and applies replacements for those texts. To add your own, or to add languages just extend or add more locale files with your desired replacement codes.

* Project-specific replacements (e.g., `#define` macros for keys/combinations):
  * Found in `tools/layouts/common.py`
* Language-specific replacements:
  * Found in `tools/layouts/<locale>.py` (e.g., `nbNO.py`, `enUS.py`)

*To add more `#define` macros or languages, follow the existing structure in `common.py` and the `<locale>.py` files.*

---

## asciimap_single_.py

To run it, simply call the script with the path and filename of the keymap.c and the name of the locale file (e.g. `nbNO` or `enUS`)

### Usage

```bash
python3 ./tools/asciimap_single.py ~/qmk_kkb/keyboards/kkb/keymaps/default/keymap.c nbNO
```

Output folder: `tools/asciimaps/user/`


## asciimaps_all.py

This script is primarily for github workflow to generate all possible keymaps and languages, and the script must be located as described below

* Should reside in `[root]/tools/asciimaps_all.py`
* Searches for keymaps in `[root]/qmk_firmware/keyboards/kkb/keymaps/`

### Usage

From the project root:

```bash
python3 ./tools/asciimaps_all.py
```

Output folder: `tools/asciimaps/`

## prepare_site_md.py

This script is primarily for github workflow to generate all possible keymaps and languages both txt and md files to be published on Github Pages, and the script must be located as described below

* Should reside in `[root]/tools/prepare_site_md.py`
* Searches for keymaps in `[root]/qmk_firmware/keyboards/kkb/keymaps/`

### Usage

From the project root:

```bash
python3 ./tools/prepare_site_md.py
```

Output folder: `tools/asciimaps/_site/` and `tools/asciimaps/_site/downloads/`
