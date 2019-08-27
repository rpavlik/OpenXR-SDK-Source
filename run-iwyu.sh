#!/bin/sh
set -x

iwyu_tool "$@" -- --mapping_file=$(cd $(dirname $0) && pwd)/mapping.imp
