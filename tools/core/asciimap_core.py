#!/usr/bin/env python3

# Copyright 2025 kkb (@ktragethon)
# SPDX-License-Identifier: GPL-2.0-or-later

"""
QMK Keymap to ASCII Layout Visualizer - Core Logic
Language-agnostic parsing and rendering engine.
"""

import re
from pathlib import Path


class KeymapVisualizer:
    """Core keymap visualization logic"""

    def __init__(self, layout_config):
        """
        Initialize with a layout configuration.

        Args:
            layout_config: Object with attributes:
                - LAYOUT_NAME: str
                - LAYOUT_DESCRIPTION: str
                - STANDARD_KEY_MAPPINGS: dict
                - CUSTOM_KEY_MAPPINGS: dict
                - RGB_KEY_MAPPINGS: dict
                - SPECIAL_KEY_MAPPINGS: dict
        """
        self.config = layout_config
        self.layout_name = layout_config.LAYOUT_NAME
        self.layout_description = layout_config.LAYOUT_DESCRIPTION
        self.standard_keys = layout_config.STANDARD_KEY_MAPPINGS
        self.custom_keys = layout_config.CUSTOM_KEY_MAPPINGS
        self.rgb_keys = layout_config.RGB_KEY_MAPPINGS
        self.special_keys = layout_config.SPECIAL_KEY_MAPPINGS

    def parse_layer_enum(self, original_content):
        """Parse any enum that defines layers"""
        layer_enum_mapping = {}

        # Try multiple enum patterns to be more flexible
        enum_patterns = [
            r'enum\s+\w*layers?\w*\s*\{(.*?)\};',
            r'enum\s*\{(.*?)\}\s*\w*layers?\w*;',
            r'typedef\s+enum\s*\{(.*?)\}\s*\w*layers?\w*;'
        ]

        enum_content = None
        for pattern in enum_patterns:
            enum_match = re.search(pattern, original_content, re.DOTALL | re.IGNORECASE)
            if enum_match:
                enum_content = enum_match.group(1)
                break

        if enum_content:
            layer_number = 0
            for line in enum_content.split('\n'):
                clean_line = re.sub(r'//.*$', '', line).strip()
                clean_line = re.sub(r'/\*.*?\*/', '', clean_line)
                clean_line = re.sub(r'///.*$', '', clean_line)

                if not clean_line or clean_line.startswith(('/', '*')):
                    continue

                layer_match = re.search(r'([A-Z_][A-Z0-9_]*)\s*(?:=\s*(\d+))?\s*,?', clean_line)
                if layer_match:
                    layer_name = layer_match.group(1)
                    explicit_number = layer_match.group(2)

                    if layer_name in ['MATRIX_ROWS', 'MATRIX_COLS', 'LAYOUT_MAX', 'LAYER_MAX']:
                        continue

                    if explicit_number is not None:
                        layer_number = int(explicit_number)

                    layer_enum_mapping[layer_name] = layer_number
                    layer_number += 1
        else:
            print("Warning: Could not find layer enum - will use positional numbering")

        return layer_enum_mapping

    def extract_layer_comments(self, original_content):
        """Extract comments and associate them with layer names"""
        layer_comments = {}
        layer_pattern = r'\[([A-Z_][A-Z0-9_]*)\]\s*=\s*LAYOUT_\w+\s*\('
        layer_matches = list(re.finditer(layer_pattern, original_content))

        for i, match in enumerate(layer_matches):
            layer_name = match.group(1)
            layer_start = match.start()

            if i > 0:
                search_start = layer_matches[i-1].end()
            else:
                search_start = 0

            preceding_content = original_content[search_start:layer_start]

            comment_patterns = [
                r'/\*\*\s*(.*?)\s*\*/',
                r'/\*\s*(.*?)\s*\*/',
                r'//\s*(.*?)(?=\n|$)',
                r'///\s*(.*?)(?=\n|$)'
            ]

            found_comment = None
            best_position = -1

            for pattern in comment_patterns:
                matches = list(re.finditer(pattern, preceding_content, re.DOTALL | re.MULTILINE))

                for comment_match in matches:
                    comment_end = comment_match.end()
                    distance_to_layer = len(preceding_content) - comment_end

                    if distance_to_layer > 200:
                        continue

                    if comment_end > best_position:
                        best_position = comment_end
                        comment_content = comment_match.group(1)
                        found_comment = comment_content

            if found_comment:
                lines = found_comment.split('\n')
                clean_lines = []

                for line in lines:
                    clean_line = re.sub(r'^\s*[\*\/]*\s?', '', line).strip()
                    if clean_line and not re.match(r'^[\*\/\s]*$', clean_line):
                        clean_lines.append(clean_line)

                if clean_lines:
                    full_comment = ' '.join(clean_lines)
                    brief_match = re.search(r'@brief\s+(.*?)(?:@\w+|$)', full_comment, re.IGNORECASE)
                    if brief_match:
                        brief_content = brief_match.group(1).strip()
                        layer_comments[layer_name] = brief_content
                    else:
                        layer_comments[layer_name] = full_comment

        return layer_comments

    def extract_file_header_comment(self, original_content):
        """Extract the main file header comment"""
        header_patterns = [
            r'^\s*/\*\*(.*?)\*/',
            r'^\s*/\*(.*?)\*/',
            r'^\s*//\s*(.*?)(?=\n\s*(?:[^/]|$))'
        ]

        for pattern in header_patterns:
            match = re.search(pattern, original_content, re.DOTALL | re.MULTILINE)
            if match:
                comment_content = match.group(1)
                lines = comment_content.split('\n')

                header_lines = []
                for line in lines:
                    clean_line = re.sub(r'^\s*[\*\/]*\s?', '', line).strip()
                    if clean_line:
                        header_lines.append(clean_line)

                if header_lines:
                    return '\n'.join(header_lines)

        return None

    def extract_keys_from_layout_content(self, layer_content, layer_name):
        """Extract keys from LAYOUT_*"""
        clean_content = re.sub(r'\s+', ' ', layer_content).strip()
        raw_tokens = clean_content.split(',')
        keys = []

        for i, token in enumerate(raw_tokens):
            token = token.strip()

            if not token:
                continue

            if not re.match(r'^[A-Z_][A-Z0-9_]*\([^)]*\)$', token):
                token = re.sub(r'\)+\s*$', '', token)

            found_key = None

            func_pattern = r'^([A-Z_][A-Z0-9_]*\([^)]*\))$'
            func_match = re.match(func_pattern, token)
            if func_match:
                found_key = func_match.group(1)
            else:
                std_pattern = r'^([A-Z_][A-Z0-9_]+)$'
                std_match = re.match(std_pattern, token)
                if std_match:
                    found_key = std_match.group(1)
                else:
                    under_pattern = r'^(_+)$'
                    under_match = re.match(under_pattern, token)
                    if under_match:
                        found_key = under_match.group(1)

            if found_key and len(found_key) > 1:
                keys.append(found_key)
            else:
                keys.append('KC_NO')

        return keys

    def parse_keymap_file(self, filepath):
        """Parse keymap.c file and extract layers with comments"""
        with open(filepath, 'r', encoding='utf-8') as f:
            original_content = f.read()

        layer_enum_mapping = self.parse_layer_enum(original_content)
        layer_comments = self.extract_layer_comments(original_content)
        file_header = self.extract_file_header_comment(original_content).strip('@brief').strip()

        content = re.sub(r'//.*$', '', original_content, flags=re.MULTILINE)
        content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)

        keymap_patterns = [
            r'const\s+uint16_t\s+PROGMEM\s+keymaps\[\]\[MATRIX_ROWS\]\[MATRIX_COLS\]\s*=\s*\{(.*?)\};',
            r'keymaps\[\]\[MATRIX_ROWS\]\[MATRIX_COLS\]\s*=\s*\{(.*?)\};',
            r'uint16_t\s+keymaps\[\]\[MATRIX_ROWS\]\[MATRIX_COLS\]\s*=\s*\{(.*?)\};'
        ]

        keymaps_content = None
        for pattern in keymap_patterns:
            match = re.search(pattern, content, re.DOTALL)
            if match:
                keymaps_content = match.group(1)
                break

        if not keymaps_content:
            print("Error: Could not find keymaps array in file")
            return {}, [], {}, None, {}

        layer_pattern = r'\[([^\]]+)\]\s*=\s*LAYOUT_\w+\s*\('
        layers = {}
        layer_order = []

        layer_starts = []
        for match in re.finditer(layer_pattern, keymaps_content):
            layer_name = match.group(1).strip()
            start_pos = match.end()
            layer_starts.append((layer_name, start_pos))

        for i, (layer_name, start_pos) in enumerate(layer_starts):
            content_start = start_pos
            paren_count = 1
            pos = start_pos

            while pos < len(keymaps_content) and paren_count > 0:
                char = keymaps_content[pos]
                if char == '(':
                    paren_count += 1
                elif char == ')':
                    paren_count -= 1
                pos += 1

            if paren_count == 0:
                layer_content = keymaps_content[content_start:pos-1]
            else:
                if i + 1 < len(layer_starts):
                    next_start = layer_starts[i + 1][1]
                    search_area = keymaps_content[content_start:next_start]
                    last_paren = search_area.rfind(')')
                    if last_paren != -1:
                        layer_content = search_area[:last_paren]
                    else:
                        layer_content = search_area
                else:
                    layer_content = keymaps_content[content_start:]
                    layer_content = re.sub(r'[)};]*\s*$', '', layer_content)

            keys = self.extract_keys_from_layout_content(layer_content, layer_name)

            while len(keys) < 69:
                keys.append('KC_NO')

            if len(keys) > 69:
                keys = keys[:69]

            layers[layer_name] = keys
            layer_order.append(layer_name)

        return layers, layer_order, layer_comments, file_header, layer_enum_mapping

    def create_layer_legend(self, layers_data, layer_order, layer_enum_mapping):
        """Create a legend mapping layer numbers to layer names"""
        legend = {}
        layer_references = set()

        for layer_name, keys in layers_data.items():
            for key in keys:
                if key.startswith(('MO(', 'TG(', 'TO(', 'UC(')):
                    layer_ref = key[3:-1]
                    layer_references.add(layer_ref)

        layer_to_number = {}

        if layer_enum_mapping:
            for layer_name in layer_order:
                if layer_name in layer_enum_mapping:
                    layer_number = layer_enum_mapping[layer_name]
                    layer_to_number[layer_name] = layer_number
                    legend[f"L{layer_number}"] = layer_name

            for layer_ref in layer_references:
                if layer_ref in layer_enum_mapping:
                    layer_number = layer_enum_mapping[layer_ref]
                    layer_to_number[layer_ref] = layer_number
                    if f"L{layer_number}" not in legend:
                        legend[f"L{layer_number}"] = layer_ref
        else:
            for i, layer_name in enumerate(layer_order):
                layer_to_number[layer_name] = i
                legend[f"L{i}"] = layer_name

            for layer_ref in layer_references:
                if layer_ref in layer_order:
                    layer_number = layer_order.index(layer_ref)
                    layer_to_number[layer_ref] = layer_number

        return legend, layer_to_number

    def convert_qmk_key_to_display(self, qmk_key, layer_to_number):
        """Convert QMK key code to display format using language-specific mappings"""

        if qmk_key.startswith('MO('):
            layer = qmk_key[3:-1]
            if layer in layer_to_number:
                return f"MO{layer_to_number[layer]}"
            else:
                return f"MO({layer})"

        if qmk_key.startswith('TG('):
            layer = qmk_key[3:-1]
            if layer in layer_to_number:
                return f"TG{layer_to_number[layer]}"
            else:
                return f"TG({layer})"

        if qmk_key.startswith('TO('):
            layer = qmk_key[3:-1]
            if layer in layer_to_number:
                return f"TO{layer_to_number[layer]}"
            else:
                return f"TO({layer})"

        if qmk_key in self.special_keys:
            return self.special_keys[qmk_key]

        if qmk_key.startswith('KC_'):
            key_name = qmk_key[3:]
            return self.standard_keys.get(key_name, key_name)

        if qmk_key.startswith('UC_'):
            key_name = qmk_key[3:]
            return self.custom_keys.get(key_name, key_name)

        if qmk_key.startswith('RGB_'):
            rgb_name = qmk_key[4:]
            return self.rgb_keys.get(rgb_name, rgb_name)

        return qmk_key[:8]

    def create_ascii_layout(self, layer_keys, layer_name, layer_to_number):
        """Create ASCII art layout with safe key access"""
        readable_keys = []
        for i, key in enumerate(layer_keys):
            readable = self.convert_qmk_key_to_display(key, layer_to_number)
            readable_keys.append(readable)

        while len(readable_keys) < 69:
            readable_keys.append('NO')

        def fit_key(key, max_width):
            return key[:max_width] if len(key) > max_width else key

        def safe_key(index, width):
            if index < len(readable_keys):
                return fit_key(readable_keys[index], width)
            else:
                return fit_key('NO', width)

        layout_lines = []

        layout_lines.append("+------+------+------+------+------+------+------+------+------+------+------+------+------+-----------+------+")
        row0_line = f"| {safe_key(0, 4):^4} |" + "".join(f" {safe_key(i, 4):^4} |" for i in range(1, 13))
        row0_line += f" {safe_key(13, 9):^9} | {safe_key(14, 4):^4} |"
        layout_lines.append(row0_line)
        layout_lines.append("+------+------+------+------+------+------+------+------+------+------+------+------+------+-----------+------+")

        row1_line = f"| {safe_key(15, 7):^7} |" + "".join(f" {safe_key(i, 4):^4} |" for i in range(16, 28))
        row1_line += f"        | {safe_key(28, 4):^4} |"
        layout_lines.append(row1_line)

        enter_key = safe_key(42, 6)
        layout_lines.append(f"+---------+------+------+------+------+------+------+------+------+------+------+------+------+ {enter_key:^6} +------+")

        row2_line = f"| {safe_key(29, 8):^8} |" + "".join(f" {safe_key(i, 4):^4} |" for i in range(30, 42))
        row2_line += f"       | {safe_key(43, 4):^4} |"
        layout_lines.append(row2_line)
        layout_lines.append("+----------+------+------+------+------+------+------+------+------+------+------+------+-------+------+------+")

        row3_line = f"| {safe_key(44, 5):^5} |" + "".join(f" {safe_key(i, 4):^4} |" for i in range(45, 56))
        row3_line += f" {safe_key(56, 8):^8} | {safe_key(57, 4):^4} | {safe_key(58, 4):^4} |"
        layout_lines.append(row3_line)
        layout_lines.append("+-------+------+------+------+------+------+------+------+------+------+------+------+----------+------+------+")

        row4_line = f"| {safe_key(59, 5):^5} | {safe_key(60, 5):^5} | {safe_key(61, 5):^5} |"
        row4_line += f" {safe_key(62, 41):^41} |" + "".join(f" {safe_key(i, 4):^4} |" for i in range(63, 69))
        layout_lines.append(row4_line)
        layout_lines.append("+-------+-------+-------+-------------------------------------------+------+------+------+------+------+------+")

        return layout_lines

    def wrap_description(self, description, max_width=111):
        """Wrap description text to fit within the keyboard layout width"""
        if not description:
            return ""

        words = description.split()
        lines = []
        current_line = ""

        for word in words:
            if len(current_line + " " + word) <= max_width:
                if current_line:
                    current_line += " " + word
                else:
                    current_line = word
            else:
                if current_line:
                    lines.append(current_line)
                current_line = word

        if current_line:
            lines.append(current_line)

        return "\n".join(f"{line}" if i == 0 else f"             {line}" for i, line in enumerate(lines))

    def format_ascii_output(self, layers_data, layer_order, layer_comments, file_header, layer_enum_mapping):
        """Format all layers into ASCII art with comments"""
        output = []

        legend, layer_to_number = self.create_layer_legend(layers_data, layer_order, layer_enum_mapping)

        output.append(f"KEYMAP VISUALIZATION, KEYBOARD:  {self.layout_description}")
        output.append(f"CREATED FOR SYSTEM-LANGUAGE:     {self.layout_name}")
        output.append("")
        output.append("=" * 111)
        output.append("")

        if legend:
            output.append("LAYER LEGEND:")
            for layer_num, layer_name in sorted(legend.items(), key=lambda x: int(x[0][1:])):
                output.append(f"  {layer_num} = {layer_name}")
            output.append("")
            output.append("=" * 111)
            output.append("")

        for i, layer_name in enumerate(layer_order):
            layer_keys = layers_data[layer_name]
            layer_num = layer_to_number.get(layer_name, i)

            output.append(f"LAYER: L{layer_num} ({layer_name})")

            if layer_name in layer_comments:
                wrapped_desc = self.wrap_description(layer_comments[layer_name], 111)
                output.append(f"  {wrapped_desc}")

            layout_lines = self.create_ascii_layout(layer_keys, layer_name, layer_to_number)

            for line in layout_lines:
                output.append(line)

            if i < len(layer_order) - 1:
                output.append("")
                output.append("")

        output.append("")
        output.append(f"Generated by QMK Keymap ASCII Visualizer ({self.layout_name})")
        output.append("=" * 111)

        return "\n".join(output)
