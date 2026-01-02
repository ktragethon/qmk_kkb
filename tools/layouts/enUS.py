# Copyright 2025 kkb (@ktragethon)
# SPDX-License-Identifier: GPL-2.0-or-later

"""US ANSI Layout Configuration"""

import importlib.util
from pathlib import Path

# Load common module
_common_path = Path(__file__).parent / 'common.py'
_spec = importlib.util.spec_from_file_location("common", _common_path)
common = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(common)

LAYOUT_NAME = "English (en-us) ANSI"
LAYOUT_DESCRIPTION = "K7 Pro ISO RGB (69 keys)"

# Language-specific key mappings for US ANSI layout
# Only the keys that differ from Norwegian/European layouts
LAYOUT_SPECIFIC_KEYS = {
    'RALT': 'Alt',    # Right Alt is just Alt
    'MINS': '-',      # Minus/hyphen
    'EQL': '=',       # Equals
    'LBRC': '[',      # Left square bracket
    'RBRC': ']',      # Right square bracket
    'SCLN': ';',      # Semicolon
    'QUOT': "'",      # Apostrophe/single quote
    'SLSH': '/',      # Forward slash
    'COMM': ',',      # Comma
    'DOT': '.',       # Period
    'GRV': '`',       # Grave/backtick
    'BSLS': '\\',     # Backslash
    # US ANSI does NOT have NUHS and NUBS (ISO-specific keys)
}

# Build complete STANDARD_KEY_MAPPINGS by combining common + specific
STANDARD_KEY_MAPPINGS = {
    **common.COMMON_MODIFIERS,
    **common.COMMON_NAVIGATION,
    **common.COMMON_NUMBERS,
    **common.COMMON_FUNCTION_KEYS,
    **common.COMMON_MEDIA_KEYS,
    **common.COMMON_LETTERS,
    **LAYOUT_SPECIFIC_KEYS  # US-specific overrides
}

# Use common mappings
CUSTOM_KEY_MAPPINGS = common.CUSTOM_KEY_MAPPINGS
RGB_KEY_MAPPINGS = common.RGB_KEY_MAPPINGS
SPECIAL_KEY_MAPPINGS = common.SPECIAL_KEY_MAPPINGS
