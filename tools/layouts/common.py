# Copyright 2025 kkb (@ktragethon)
# SPDX-License-Identifier: GPL-2.0-or-later

"""
Common key mappings shared across all keyboard layouts.
These mappings are language/layout-independent.
"""

# Custom/user-defined key mappings (UC_ prefix keys)
# These are YOUR custom keycodes defined in config.h
# Same across all layouts since they're user-defined
CUSTOM_KEY_MAPPINGS = {
    'EXCL': '!',    # Exclamation mark
    'LBRC': '[',    # Square bracket left
    'RBRC': ']',    # Square bracket right
    'LPRN': '(',    # Parenthesis left
    'RPRN': ')',    # Parenthesis right
    'LCBR': '{',    # Curly brace left
    'RCBR': '}',    # Curly brace right
    'LABK': '<',    # Angle bracket left
    'RABK': '>',    # Angle bracket right
    'PIPE': '|',    # Pipe/vertical bar
    'BSLS': '\\',   # Backslash
    'PLUS': '+',    # Plus sign
    'ACUT': "'",    # Acute accent/apostrophe
    'AA': 'Å',      # Å - A with ring above
    'DIAE': '¨',    # Diaeresis/umlaut
    'OSTR': 'Ø',    # Ø - O with stroke
    'AE': 'Æ',      # Æ - AE ligature
    'QUOT': "'",    # Quote/apostrophe
    'LESS': '<',    # Less than
    'MINS': '-',    # Minus/hyphen
    'AMPR': '&',    # Ampersand
    'EQUA': '=',    # Equal sign
    'VMUL': '*',    # Multiply (calculator)
    'VDIV': '/',    # Divide (calculator)
    'VSUB': '-',    # Subtract (calculator)
    'VADD': '+',    # Add (calculator)
    'QUST': '?',    # Question mark
    'QOTE': '"',    # Quote
    'SQOT': "'",    # Single quote
    'SCOL': ';',    # Semicolon
    'COLO': ':'     # Colon
}

# RGB control key mappings
# Hardware RGB controls - same across all layouts
RGB_KEY_MAPPINGS = {
    'TOG': 'RGB',   # Toggle RGB on/off
    'MOD': 'RGB+',  # Next RGB mode
    'RMOD': 'RGB-', # Previous RGB mode
    'HUI': 'H+',    # Hue increase
    'HUD': 'H-',    # Hue decrease
    'SAI': 'S+',    # Saturation increase
    'SAD': 'S-',    # Saturation decrease
    'VAI': 'V+',    # Value/brightness increase
    'VAD': 'V-',    # Value/brightness decrease
    'SPI': 'SP+',   # Speed increase
    'SPD': 'SP-'    # Speed decrease
}

# Special key mappings
# QMK firmware special keys - same across all layouts
SPECIAL_KEY_MAPPINGS = {
    '_______': 'TRNS',  # Transparent (passes through to lower layer)
    'KC_TRNS': 'TRNS',  # Transparent (explicit form)
    'KC_NO': 'NO',      # No operation (disabled key)
    'NK_TOGG': 'NKRO',  # NKRO (N-Key Rollover) toggle
    'QK_BOOT': 'Boot',  # Enter bootloader mode
    'RESET': 'Reset'    # Reset keyboard
}

# Common modifier and navigation keys
# These are typically the same across layouts (just the labels)
COMMON_MODIFIERS = {
    'ESC': 'Esc', 'BSPC': 'Bspc', 'DEL': 'Del', 'TAB': 'Tab', 'ENT': 'Ent',
    'CAPS': 'Caps', 'LSFT': 'Shift', 'RSFT': 'Shift', 'SPC': 'Space',
    'LCTL': 'Ctrl', 'LGUI': 'Win', 'LALT': 'Alt',
}

# Navigation keys (same across layouts)
COMMON_NAVIGATION = {
    'HOME': 'Home', 'PGUP': 'PgUp', 'PGDN': 'PgDn', 
    'LEFT': 'Left', 'DOWN': 'Down', 'UP': 'Up', 'RGHT': 'Right',
}

# Function keys (same across layouts)
COMMON_FUNCTION_KEYS = {
    'F1': 'F1', 'F2': 'F2', 'F3': 'F3', 'F4': 'F4', 'F5': 'F5', 'F6': 'F6',
    'F7': 'F7', 'F8': 'F8', 'F9': 'F9', 'F10': 'F10', 'F11': 'F11', 'F12': 'F12',
}

# Media and system keys (same across layouts)
COMMON_MEDIA_KEYS = {
    'MUTE': 'Mute', 'VOLD': 'Vol-', 'VOLU': 'Vol+', 'MPRV': 'Prev',
    'MNXT': 'Next', 'MPLY': 'Play', 'MSTP': 'Stop',
    'BRIU': 'BRI+', 'BRID': 'BRI-', 'TASK': 'Task', 'FILE': 'File',
    'CALC': 'Calc', 'MSEL': 'Media', 'MYCM': 'MyPC', 'MAIL': 'Mail',
    'WHOM': 'Home', 'FIND': 'Find',
}

# Numbers (same across layouts)
COMMON_NUMBERS = {
    '1': '1', '2': '2', '3': '3', '4': '4', '5': '5',
    '6': '6', '7': '7', '8': '8', '9': '9', '0': '0',
}

# Letters (same physical keys across layouts)
COMMON_LETTERS = {
    'Q': 'Q', 'W': 'W', 'E': 'E', 'R': 'R', 'T': 'T', 'Y': 'Y', 'U': 'U',
    'I': 'I', 'O': 'O', 'P': 'P', 'A': 'A', 'S': 'S', 'D': 'D', 'F': 'F',
    'G': 'G', 'H': 'H', 'J': 'J', 'K': 'K', 'L': 'L', 'Z': 'Z', 'X': 'X',
    'C': 'C', 'V': 'V', 'B': 'B', 'N': 'N', 'M': 'M'
}
