#!/usr/bin/env python3 -i
# Copyright 2019 Collabora, Ltd
# SPDX-License-Identifier: BSL-1.0
# Author: Ryan Pavlik <ryan.pavlik@collabora.com>

import re

import networkx as nx
from networkx.algorithms.dag import topological_sort


class HeaderMergerBase:
    def __init__(self):
        self.graph = nx.DiGraph()
        # self.file_contents = {}
        # self.file_includes = {}
        self.paths = {}
        self.include_re = re.compile(
            r'^ *# *include *(?P<quoted_name>(?P<open>["<])(?P<name>[^">]*)[">])')

    def is_start_marker(self, line):
        """Return True if lines following this one should be treated as "contents".

        You must implement this."""
        raise NotImplementedError

    def is_keeper_start_marker(self, line):
        """Return True if this line and all lines following this one should be treated as "contents".

        You may implement this."""
        return False

    def is_end_marker(self, line):
        """Return True if processing of this file should stop.

        You must implement this."""
        raise NotImplementedError

    def get_external_include_from_match(self, match):
        """Return the string that represents an external include, or None if the match represents an internal header include that should be replaced.

        The basic implementation here assumes that angle-brackets means external include.

        A match will be transformed into a dependency in the graph if this returns True.
        It will be kept as an external include if this returns False."""
        if self.is_match_angle_brackets(match):
            # Regenerate with no extra spaces, so the set can de-duplicate nicely.
            return "#include {}".format(match.group("quoted_name"))
        return None

    def is_match_angle_brackets(self, match):
        return match.group("open") == "<"

    def parse_files(self, files):
        for fn in files:
            self.parse_file(fn)

    def parse_file(self, fn, name=None):
        if not name:
            name = fn.name
        self.paths[name] = fn
        with open(str(fn), 'r', encoding='utf') as f:
            self.parse_from_stream(name, f)

    def add_file(self, name, contents=None, other_includes=None):
        G = self.graph
        if not contents:
            contents = []
        if not other_includes:
            other_includes = set()
        G.add_node(name)
        G.nodes[name]['contents'] = contents
        G.nodes[name]['includes'] = other_includes

    def handle_line_before_content(self, name, line, attributes):
        """May implement to add extra attributes when processing a file."""
        pass

    def parse_from_stream(self, name, stream):
        # locals
        G = self.graph
        lines = []
        other_includes = set()
        copyrights = set()

        # Add graph node and attributes
        G.add_node(name)
        G.nodes[name]['contents'] = lines
        G.nodes[name]['includes'] = other_includes

        started = False

        for line in stream:
            line = line.rstrip()
            if not started:
                match = self.include_re.match(line)
                if match:
                    # An include line
                    external_include = self.get_external_include_from_match(
                        match)
                    if external_include:
                        other_includes.add(external_include)
                    else:
                        # the current name depends on the included name
                        included_name = match.group("name")
                        G.add_edge(name, included_name)
                    continue  # with next line

            # Not an include line - what kind of line is it?

            # Is it the marker that indicates the next line is the first to keep as "content"?
            if not started:
                if self.is_keeper_start_marker(line):
                    started = True
                    lines.append(line)
                    continue  # with next line

                if self.is_start_marker(line):
                    started = True
                    continue  # with next line

                self.handle_line_before_content(name, line, G.nodes[name])
                

            # Is it the marker that indicates that there is no more content?
            if started and self.is_end_marker(line):
                return

            # If we're in a "content" line, append it to the list
            if started:
                lines.append(line)

        if not started:
            print(
                'Warning! Got no content from {}, maybe missing start marker?'.format(name))

    def get_sorted_deps(self, name=None, names=None):
        """Returns an appropriately-sorted list of filenames that are name or depended-on by name.

        Each file appears earlier in the list than any file including it.

        If name is None, gets all sorted deps."""
        if name or names:
            if name:
                names = [name]
            nodes = set(names)
            for n in names:
                nodes.update(self.graph.successors(n))
            graph = self.graph.subgraph(nodes)
        else:
            graph = self.graph
        return list(reversed(list(topological_sort(graph))))

    def get_union_of_attribute_of(self, attribute_name, names):
        "Return the union of a set attribute from the given file names."
        empty = set()
        return set().union(*(self.graph.nodes[name].get(attribute_name, empty) for name in names))

    def get_other_includes_of(self, names):
        "Return the set of other includes from the given file names."
        return self.get_union_of_attribute_of('includes', names)

    def get_contents_of(self, names, origin_comment=False):
        "Return a list of lines from the given file names, in the given order."
        contents = []
        for name in names:
            file_contents = self.graph.nodes[name]['contents']
            if not file_contents:
                # contents.append(
                #     '// Contents of {} would be here if not empty'.format(name))
                continue
            if origin_comment:
                contents.append('')
                contents.append("// BEGIN contents of {}".format(name))
            contents.extend(file_contents)
            if origin_comment:
                contents.append("// END contents of {}".format(name))
                contents.append('')
        return contents
