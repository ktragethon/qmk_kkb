# Copyright 2025 kkb (@ktragethon)
# SPDX-License-Identifier: GPL-2.0-or-later

"""Norwegian (nb-NO) ISO Layout Configuration"""

import importlib.util
from pathlib import Path

# Load common module
_common_path = Path(__file__).parent / 'common.py'
_spec = importlib.util.spec_from_file_location("common", _common_path)
common = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(common)

LAYOUT_NAME = "Norwegian (nb-NO) ISO"
LAYOUT_DESCRIPTION = "K7 Pro ISO RGB (69 keys)"

# Language-specific key mappings for Norwegian ISO layout
# Only the keys that differ from US layout
LAYOUT_SPECIFIC_KEYS = {
    'RALT': 'AltGr',  # Right Alt is AltGr on European keyboards
    'MINS': '+',      # Plus sign (US: minus)
    'EQL': '\\',      # Backslash (US: equals)
    'LBRC': 'Å',      # Å - A with ring above (US: left bracket)
    'RBRC': '¨',      # ¨ - Diaeresis/umlaut (US: right bracket)
    'SCLN': 'Ø',      # Ø - O with stroke (US: semicolon)
    'QUOT': 'Æ',      # Æ - AE ligature (US: apostrophe)
    'NUHS': "'",      # Apostrophe (ISO-specific key next to Enter)
    'NUBS': '<',      # Less than (ISO-specific extra key left of Z)
    'SLSH': '-',      # Minus/hyphen (US: forward slash)
    'COMM': ',',      # Comma (same as US, but included for completeness)
    'DOT': '.',       # Period (same as US)
    'GRV': '|',       # Pipe (US: grave/backtick)
    'TILD': '§',      # Section sign (alternative on GRV key)
    'BSLS': '*',      # Asterisk (US: backslash)
}

# Build complete STANDARD_KEY_MAPPINGS by combining common + specific
STANDARD_KEY_MAPPINGS = {
    **common.COMMON_MODIFIERS,
    **common.COMMON_NAVIGATION,
    **common.COMMON_NUMBERS,
    **common.COMMON_FUNCTION_KEYS,
    **common.COMMON_MEDIA_KEYS,
    **common.COMMON_LETTERS,
    **LAYOUT_SPECIFIC_KEYS  # Norwegian-specific overrides
}

# Use common mappings
CUSTOM_KEY_MAPPINGS = common.CUSTOM_KEY_MAPPINGS
RGB_KEY_MAPPINGS = common.RGB_KEY_MAPPINGS
SPECIAL_KEY_MAPPINGS = common.SPECIAL_KEY_MAPPINGS
