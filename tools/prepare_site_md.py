#!/usr/bin/env python3

# Copyright 2025 kkb (@ktragethon)
# SPDX-License-Identifier: GPL-2.0-or-later

import os
import sys
import shutil
from pathlib import Path

import asciimaps_all

# Status
results = {
    'success': 0,
    'failed': 0,
    'files': []
}

# Create config in site directory
def write_site_config(dir):
    try:
        with open(dir / '_config.yml', 'w') as f:
            f.write("""remote_theme: pages-themes/hacker@v0.2.0
plugins:
- jekyll-remote-theme
title: KKB Keymap Visualizations
description: Auto-generated ASCII visualizations
show_downloads: false
""")
            
    except (IOError, OSError):
        sys.exit(1)

# Create index
def write_index(dir):
    try:
        with open(dir / 'index.md', 'w') as f:
            f.write("""
# Available Keymaps

View or download keymaps in various formats.

""")
        return True
    except (IOError, OSError):
        return False

# Process text-files and transform them to .md
def process_txt_files(source_dir, dest_dir, down_dir):
    try:
        with open(dest_dir / 'index.md', 'a') as f:
            f.write(f"| View (html) | View | Download |\n")
            f.write(f"| :--- | ----: | ----: |\n")

        for txt_file in sorted(source_dir.glob('*.txt')):
            name = txt_file.stem
            name_txt = f"{name}.txt"
            name_md = f"{name}.md"
            name_html = f"{name}.html"
            name_md_raw = f"{name}.md.raw" # Add .raw to .md files to avoid jekyll processing

            # Append link to index
            with open(dest_dir / 'index.md', 'a') as f:
                f.write(f'| [{name}]({name_html}) | [.txt](downloads/{name_txt}) | <a href="downloads/{name_md_raw}" download="{name_md}">.md</a> |\n')

            # Read the txt file content
            content = txt_file.read_text()

            # Create markdown file with frontmatter and code block
            output_path = dest_dir / name_md
            output_path.write_text(f"""---
title: {name}
---

# {name}

```
{content}
```

""")
                        
            # Copy files into the downloads directory
            shutil.copyfile(source_dir / name_txt, down_dir / name_txt)
            shutil.copyfile(dest_dir / name_md, down_dir / name_md_raw)

            results['success'] += 1
            results['files'].append(f"{dest_dir}/{name_md}")

        return True
    except (IOError, OSError):
        return False

# Call the main script to generate the text asciimaps
print(f"Calling asciimaps_all to generate text files\n")
asciimaps_all.main()

print("=" * 70)
print(f"\nProcessed asciimaps, start transforming")
print("")

# Get the directory where this script is located
script_dir = Path(__file__).parent.resolve()

# Check that the folders exist
asciimaps_dir = script_dir / 'asciimaps'
if not asciimaps_dir.exists() or not asciimaps_dir.is_dir():
    print(f"Error: Required directory '{asciimaps_dir}' does not exist", file=sys.stderr)
    sys.exit(1)

print(f"Required subfolders exist, create subfolder for the site")

# Create _site directory relative to script location
site_dir = script_dir / 'asciimaps' / '_site'
site_dir.mkdir(parents=True, exist_ok=True)

# Check that the _site directory exists
if not site_dir.exists() or not site_dir.is_dir():
    print(f"Error: Required directory '{site_dir}' does not exist", file=sys.stderr)
    sys.exit(1)

# Create downloads directory relative to site location
downloads_dir = site_dir / 'downloads'
downloads_dir.mkdir(parents=True, exist_ok=True)

# Check that the _site directory exists
if not downloads_dir.exists() or not downloads_dir.is_dir():
    print(f"Error: Required directory '{downloads_dir}' does not exist", file=sys.stderr)
    sys.exit(1)

print(f"Process original keymaps and index")

# Create site-config
write_site_config(site_dir)

# Create the index file
if write_index(site_dir):    
    results['success'] += 1
    results['files'].append(f"{site_dir}/index.md")
else:
    results['failed'] += 1
    print(f"Failed to create {site_dir}/index.md", file=sys.stderr)
    sys.exit(1)


# Process all txt files in asciimaps directory (relative to script)
process_txt_files(asciimaps_dir, site_dir, downloads_dir)

# Summary
print("=" * 70)
print("SUMMARY")
print("=" * 70)
print(f"Total processed: {results['success']}")
print(f"Failed: {results['failed']}")
print(f"Output directory: {site_dir}")
print()

if results['failed'] > 0:
    sys.exit(1)
