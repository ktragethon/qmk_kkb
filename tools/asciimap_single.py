#!/usr/bin/env python3

# Copyright 2025 kkb (@ktragethon)
# SPDX-License-Identifier: GPL-2.0-or-later

"""
QMK Keymap to ASCII Layout Visualizer
Main executable script - loads layout configs and runs visualization.
"""

import sys
import importlib.util
from pathlib import Path

# Get the tools directory
tools_dir = Path(__file__).resolve().parent

# Import KeymapVisualizer from core subfolder
core_path = tools_dir / 'core' / 'asciimap_core.py'
spec = importlib.util.spec_from_file_location("asciimap_core", core_path)
asciimap_core = importlib.util.module_from_spec(spec)
spec.loader.exec_module(asciimap_core)
KeymapVisualizer = asciimap_core.KeymapVisualizer


def load_layout_config(layout_code):
    """
    Load a layout configuration module.

    Args:
        layout_code: Layout code (e.g., 'nbNO', 'enUS')

    Returns:
        Layout configuration module
    """
    layout_path = tools_dir / 'layouts' / f'{layout_code}.py'

    if not layout_path.exists():
        available_layouts = [f.stem for f in (tools_dir / 'layouts').glob('*.py') 
                           if f.stem != '__init__' and f.stem != 'template']
        print(f"Error: Layout '{layout_code}' not found")
        print(f"Available layouts: {', '.join(sorted(available_layouts))}")
        sys.exit(1)

    spec = importlib.util.spec_from_file_location(layout_code, layout_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)

    return module


def list_available_layouts():
    """List all available layout configurations"""
    layouts_dir = tools_dir / 'layouts'
    if not layouts_dir.exists():
        return []

    available_layouts = [f.stem for f in layouts_dir.glob('*.py') 
                        if f.stem != '__init__' and f.stem != 'template']
    return sorted(available_layouts)


def print_usage():
    """Print usage information"""
    print("Usage: python asciimap_single.py <path_to_keymap.c> <layout_code>")
    print()
    print("Arguments:")
    print("  <path_to_keymap.c>  Path to the keymap.c file to visualize")
    print("  <layout_code>       Layout configuration to use")
    print()

    available_layouts = list_available_layouts()
    if available_layouts:
        print("Available layout codes:")
        for layout in available_layouts:
            print(f"  {layout}")
    else:
        print("No layout configurations found in tools/layouts/")

    print()
    print("Examples:")
    print("  python asciimap_single.py keyboards/kkb/keymaps/default/keymap.c nbNO")
    print("  python asciimap_single.py keyboards/kkb/keymaps/default/keymap.c enUS")


def main():
    # Check argument count - MUST have exactly 2 arguments (script receives 3 with script name)
    if len(sys.argv) != 3:
        print("Error: Both keymap path and layout code are required")
        print()
        print_usage()
        sys.exit(1)

    keymap_path = Path(sys.argv[1])
    layout_code = sys.argv[2]

    # Validate keymap file exists
    if not keymap_path.exists():
        print(f"Error: File '{keymap_path}' does not exist")
        sys.exit(1)

    # Validate it's actually a file
    if not keymap_path.is_file():
        print(f"Error: '{keymap_path}' is not a file")
        sys.exit(1)

    # Load layout configuration
    print(f"Load layout: {layout_code}")
    layout_config = load_layout_config(layout_code)

    # Create visualizer
    visualizer = KeymapVisualizer(layout_config)

    # Parse keymap file
    print(f"Parsing: {keymap_path}")
    print(f"Layout: {layout_config.LAYOUT_NAME}")
    print()

    layers_data, layer_order, layer_comments, file_header, layer_enum_mapping = \
        visualizer.parse_keymap_file(keymap_path)

    if not layers_data:
        print("Error: No layers found in keymap file!")
        sys.exit(1)

    # Create ASCII output
    ascii_output = visualizer.format_ascii_output(
        layers_data, layer_order, layer_comments, file_header, layer_enum_mapping
    )

    # Create output directory if it doesn't exist
    output_dir_top = tools_dir / 'asciimaps'
    output_dir_top.mkdir(exist_ok=True)
    output_dir = output_dir_top / 'user'
    output_dir.mkdir(exist_ok=True)

    # Save to file in asciimaps folder (./asciimaps/user/)
    keymap_folder = keymap_path.parent.name
    output_filename = f"{keymap_folder}_{layout_code}.txt"
    output_path = output_dir / output_filename

    with open(output_path, 'w', encoding='utf-8') as f:
        f.write(ascii_output)

    print(f"✓ ASCII layout saved to: {output_path}")
    print(f"✓ Found {len(layers_data)} layers: {', '.join(layer_order)}")
    print(f"✓ Layout: {layout_config.LAYOUT_NAME}")


if __name__ == "__main__":
    main()
