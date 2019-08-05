#!/usr/bin/env python3
# Copyright 2019 Collabora, Ltd
# SPDX-License-Identifier: BSL-1.0
# Author: Ryan Pavlik <ryan.pavlik@collabora.com>

from pathlib import Path

from HeaderMerger import HeaderMergerBase

REPO_ROOT = Path(__file__).resolve().parent.parent
INCLUDE_DIR = REPO_ROOT / 'include' / 'openxr'
FULL_MERGE_OUTFILE = REPO_ROOT / 'openxr_loader.cpp'

TEMPLATE_FILE = REPO_ROOT / 'src' / 'loader' / 'loader_core.cpp'

LOADER_SPECIFIC_SOURCES = (REPO_ROOT/'src'/'loader'/fn for fn in ('api_layer_interface.cpp',
                                                                  'loader_core.cpp',
                                                                  'loader_instance.cpp',
                                                                  'loader_logger.cpp',
                                                                  'loader_logger_recorders.cpp',
                                                                  'manifest_file.cpp',
                                                                  'runtime_interface.cpp',
                                                                  'xr_generated_loader.cpp'))
COMMON_SOURCES = (REPO_ROOT/'src'/'common'/fn for fn in ('filesystem_utils.cpp',
                                                         'hex_and_handles.cpp',))
DISPATCH_TABLE_SOURCES = (REPO_ROOT/'src'/'xr_generated_dispatch_table.c',)

JSONCPP_SOURCE = REPO_ROOT/'src'/'external'/'jsoncpp'/'dist'/'jsoncpp.cpp'
JSONCPP_HEADER = REPO_ROOT/'src'/'external'/'jsoncpp'/'dist'/'json'/'json.h'
DIRS = (
    REPO_ROOT/'src',
    REPO_ROOT/'src'/'common',
    REPO_ROOT/'src'/'loader',
)

# FORCED_PREFIX_HEADER = REPO_ROOT/'src'/'common'/'xr_dependencies.h'
FORCED_PREFIX_HEADER = 'xr_dependencies.h'

START_MARKER = '// source-merger-content-start'
# NAMESPACE_STRING = "namespace typepack"
# START_NAMESPACE = NAMESPACE_STRING + " {"
# END_NAMESPACE = "} // " + NAMESPACE_STRING

HEADER_SUFFIXES = set(('.h', '.hpp'))

GENERATED_WARNING = """
// NOTE: This is a generated single-file version of the OpenXR loader - do not edit directly!
// Instead, edit the individual source files and regenerate this with combine_headers.py.
"""


def get_headers():
    for base_dir in DIRS:
        for fn in base_dir.iterdir():
            if not fn.is_file():
                continue
            if fn.suffix in HEADER_SUFFIXES:
                yield fn


def join_lines(lines):
    return '\n'.join(lines) + '\n'


def get_file_prefix():
    prefix = []
    with open(TEMPLATE_FILE, 'r', encoding='utf-8') as f:

        for line in f:
            line = line.rstrip()
            # Before the includes
            if line.startswith('// Copyright'):
                # We'll combine these later
                continue

            if "Header including" in line:
                # Adjust the @brief comment line
                line = line.replace(
                    "Header including", "Generated single-file header containing")

            # looking for the first include - the last line in this segment
            if "#include" in line:
                break
            if "Author:" in line:
                # Stick the warning in here
                prefix.append(GENERATED_WARNING)
                continue
            prefix.append(line)
    return prefix


class LoaderMerger(HeaderMergerBase):
    def __init__(self):
        self.header_files = [fn for fn in get_headers()]
        self.header_filenames = set((fn.name for fn in self.header_files))
        self.known_filenames = set((fn.name for fn in self.header_files))

        super().__init__()

        # Skip common_config.h: make it an empty file
        self.known_filenames.add('common_config.h')
        self.add_file('common_config.h')

        if JSONCPP_SOURCE.exists():
            self.known_filenames.add(JSONCPP_SOURCE.name)
        if JSONCPP_HEADER.exists():
            self.known_filenames.add('json/json.h')

    def get_external_include_from_match(self, match):
        """Identify external includes by checking if this file is in our group of files to merge."""
        name = match.group("name")
        quoted_name = match.group("quoted_name")
        if name.startswith('openxr/'):
            # Normalize openxr headers with angle brackets
            quoted_name = '<{}>'.format(name)

        if name not in self.known_filenames:
            # Regenerate with no extra spaces, so the set can de-duplicate nicely.
            return "#include {}".format(quoted_name)
        return None

    def is_keeper_start_marker(self, line):
        return line in ('#ifdef __cplusplus',
                        # for xr_linear
                        '#define MATH_PI 3.14159265358979323846f',
                        # for xr_generated_loader.cpp
                        '// Unordered maps to lookup the instance for a given object type',
                        # jsoncpp
                        '#ifndef JSON_IS_AMALGAMATION',
                        '#ifndef JSON_AMALGATED_H_INCLUDED',
                        )

    def is_start_marker(self, line):
        return line == START_MARKER

    def is_end_marker(self, line):
        # All other files just go to the end.
        return line == '#endif  // XR_LINEAR_H_'

    def handle_line_before_content(self, name, line, attributes):
        def add_to_set(k, v):
            if k not in attributes:
                attributes[k] = set()
            attributes[k].add(v)

        if line.startswith('// Copyright'):
            add_to_set('copyrights', line)
        elif 'Author:' in line:
            add_to_set('authors', line)

    def get_copyrights_of(self, names):
        "Return the set of copyright lines from the given file names."
        return self.get_union_of_attribute_of('copyrights', names)

    def parse_all(self):
        if JSONCPP_SOURCE.exists():
            self.parse_file(JSONCPP_SOURCE)
        if JSONCPP_HEADER.exists():
            self.parse_file(JSONCPP_HEADER, 'json/json.h')
        
        self.parse_files(self.header_files)
        self.parse_files(LOADER_SPECIFIC_SOURCES)
        self.parse_files(COMMON_SOURCES)
        self.parse_files(DISPATCH_TABLE_SOURCES)

    def write(self, fn):
        sorted_names = self.get_sorted_deps()
        sorted_headers = self.get_sorted_deps(names=self.header_filenames)
        already_included = set(sorted_headers)
        print('\n'.join(sorted_names))

        lines = list(sorted(self.get_copyrights_of(sorted_names)))
        lines.extend(get_file_prefix())
        lines.extend(sorted(self.get_union_of_attribute_of('authors', sorted_names)))
        # Manually put this first.
        front_headers = [FORCED_PREFIX_HEADER, 'exception_handling.hpp']
        lines.extend(self.get_contents_of(front_headers))

        # Remove from the list
        sorted_headers = [x for x in sorted_headers if x not in front_headers]

        # Finish combining headers
        lines.extend(sorted(self.get_other_includes_of(sorted_headers)))
        lines.extend(self.get_contents_of(sorted_headers, origin_comment=True))

        # Figure out the non-headers we need to include.
        sources = [x for x in sorted_names if x not in already_included]
        lines.extend(sorted(self.get_other_includes_of(sources)))
        lines.extend(self.get_contents_of(sources, origin_comment=True))

        with open(fn, 'w', encoding='utf-8') as f:
            f.write(join_lines(lines))


if __name__ == "__main__":
    full_merge = LoaderMerger()
    full_merge.parse_all()
    full_merge.write(str(FULL_MERGE_OUTFILE))
