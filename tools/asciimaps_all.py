#!/usr/bin/env python3

# Copyright 2025 kkb (@ktragethon)
# SPDX-License-Identifier: GPL-2.0-or-later

"""
Generate ASCII maps for all keymaps and all layouts.
Used for batch generation in CI/CD pipelines.
"""

import sys
import importlib.util
from pathlib import Path
from datetime import datetime

# Add tools directory to path for imports
tools_dir = Path(__file__).resolve().parent
sys.path.insert(0, str(tools_dir))

# Import from core subfolder
core_path = tools_dir / 'core' / 'asciimap_core.py'
spec = importlib.util.spec_from_file_location("asciimap_core", core_path)
asciimap_core = importlib.util.module_from_spec(spec)
spec.loader.exec_module(asciimap_core)
KeymapVisualizer = asciimap_core.KeymapVisualizer


def load_layout_config(layout_code):
    """Load a layout configuration module"""
    layout_path = tools_dir / 'layouts' / f'{layout_code}.py'

    if not layout_path.exists():
        print(f"Warning: Layout '{layout_code}' not found, skipping")
        return None

    spec = importlib.util.spec_from_file_location(layout_code, layout_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)

    return module


def discover_layouts():
    """Discover all available layout configurations"""
    layouts_dir = tools_dir / 'layouts'
    if not layouts_dir.exists():
        return []

    layouts = [f.stem for f in layouts_dir.glob('*.py') 
              if f.stem not in ('__init__', 'common', 'template')]

    return sorted(layouts)


def discover_keymaps(keyboards_dir):
    """Discover all keymap.c files in the keyboards directory"""
    keymaps = []

    # Look for all keymap.c files
    for keymap_file in keyboards_dir.rglob('keymap.c'):
        # Get the keymap name (parent directory name)
        keymap_name = keymap_file.parent.name

        # Get the keyboard path relative to keyboards/
        try:
            rel_path = keymap_file.relative_to(keyboards_dir)
            keyboard_name = rel_path.parts[0]  # e.g., 'kkb'
        except ValueError:
            continue

        keymaps.append({
            'path': keymap_file,
            'keymap_name': keymap_name,
            'keyboard_name': keyboard_name,
            'display_name': f"{keyboard_name}/{keymap_name}"
        })

    return sorted(keymaps, key=lambda x: x['display_name'])


def generate_ascii_map(keymap_info, layout_code, output_dir):
    """Generate ASCII map for a specific keymap and layout"""
    keymap_path = keymap_info['path']

    try:
        # Load layout configuration
        layout_config = load_layout_config(layout_code)
        if not layout_config:
            return False

        # Create visualizer
        visualizer = KeymapVisualizer(layout_config)

        # Parse keymap file
        layers_data, layer_order, layer_comments, file_header, layer_enum_mapping = \
            visualizer.parse_keymap_file(keymap_path)

        if not layers_data:
            print(f"  ⚠️  No layers found in {keymap_info['display_name']}")
            return False

        # Create ASCII output
        ascii_output = visualizer.format_ascii_output(
            layers_data, layer_order, layer_comments, file_header, layer_enum_mapping
        )

        # Create output filename
        output_filename = f"{keymap_info['keyboard_name']}_{keymap_info['keymap_name']}_{layout_code}.txt"
        output_path = output_dir / output_filename

        # Write output
        with open(output_path, 'w', encoding='utf-8') as f:
            f.write(ascii_output)

        print(f"  ✓ Generated: {output_filename}")
        return True

    except Exception as e:
        print(f"  ✗ Error generating {keymap_info['display_name']} with {layout_code}: {e}")
        return False


def create_index_file(output_dir, results):
    """Create an index file listing all generated maps"""
    index_path = output_dir / 'index.md'

    with open(index_path, 'w', encoding='utf-8') as f:
        f.write("# Generated ASCII Keyboard Layouts\n\n")
        f.write(f"Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n\n")
        f.write(f"Total layouts generated: {results['success']}\n")

        if results['failed'] > 0:
            f.write(f"Failed: {results['failed']}\n")

        f.write("\n## Available Layouts\n\n")

        # Group by keyboard/keymap
        grouped = {}
        for filename in sorted(results['files']):
            # Parse filename: keyboard_keymap_layout.txt
            parts = filename.rsplit('_', 1)
            if len(parts) == 2:
                keymap_part = parts[0]
                layout = parts[1].replace('.txt', '')

                if keymap_part not in grouped:
                    grouped[keymap_part] = []
                grouped[keymap_part].append((layout, filename))

        for keymap, layouts in sorted(grouped.items()):
            f.write(f"### {keymap}\n\n")
            for layout, filename in sorted(layouts):
                f.write(f"- [{layout}]({filename})\n")
            f.write("\n")


def main():
    print("=" * 70)
    print("QMK ASCII Map Batch Generator")
    print("=" * 70)
    print()

    # Get project root (assuming we're in tools/)
    project_root = tools_dir.parent
    keyboards_dir = project_root / 'keyboards'

    if not keyboards_dir.exists():
        print(f"Error: keyboards directory not found at {keyboards_dir}")
        sys.exit(1)

    # Create output directory
    output_dir = tools_dir / 'asciimaps'
    output_dir.mkdir(exist_ok=True)
    print(f"Output directory: {output_dir}")
    print()

    # Discover layouts
    print("Discovering layout configurations...")
    layouts = discover_layouts()
    if not layouts:
        print("Error: No layout configurations found")
        sys.exit(1)

    print(f"Found {len(layouts)} layout(s): {', '.join(layouts)}")
    print()

    # Discover keymaps
    print("Discovering keymaps...")
    keymaps = discover_keymaps(keyboards_dir)
    if not keymaps:
        print("Error: No keymaps found")
        sys.exit(1)

    print(f"Found {len(keymaps)} keymap(s):")
    for keymap in keymaps:
        print(f"  - {keymap['display_name']}")
    print()

    # Generate all combinations
    print("=" * 70)
    print("Generating ASCII maps...")
    print("=" * 70)
    print()

    results = {
        'success': 0,
        'failed': 0,
        'files': []
    }

    total = len(keymaps) * len(layouts)
    current = 0

    for keymap in keymaps:
        print(f"Keymap: {keymap['display_name']}")

        for layout in layouts:
            current += 1
            print(f"  [{current}/{total}] Layout: {layout}...", end=" ")

            if generate_ascii_map(keymap, layout, output_dir):
                results['success'] += 1
                results['files'].append(f"{keymap['keyboard_name']}_{keymap['keymap_name']}_{layout}.txt")
            else:
                results['failed'] += 1

        print()

    # Create index file
    print("Creating index file...")
    create_index_file(output_dir, results)
    print()

    # Summary
    print("=" * 70)
    print("SUMMARY")
    print("=" * 70)
    print(f"Total generated: {results['success']}")
    print(f"Failed: {results['failed']}")
    print(f"Output directory: {output_dir}")
    print()

    if results['failed'] > 0:
        sys.exit(1)


if __name__ == "__main__":
    main()
