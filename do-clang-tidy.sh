#!/bin/bash -x

if [ ! "$BUILD_DIR" ]; then
    BUILD_DIR=build/
fi

if [ "${1}" ] && [ "${1}" != "-fix" ]; then
    BUILD_DIR=$1
    shift
fi

set -e
SRCROOT=$(cd $(dirname $0) && pwd)

RUNNER=${RUNNER:-run-clang-tidy-7}

find $SRCROOT/src \
    -not \( -wholename $SRCROOT/src/external/\* \) \
    -and \( -name \*.cpp -or -name \*.c \) \
    -exec ${RUNNER} -p ${BUILD_DIR} -extra-arg=--std=c++11 "$@" \{\} +
