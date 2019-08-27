#!/bin/sh
set -e

BUILDDIR=build-temp

rm -rf $BUILDDIR
mkdir -p $BUILDDIR
cmake -S . -B $BUILDDIR -G Ninja
ninja -C $BUILDDIR
