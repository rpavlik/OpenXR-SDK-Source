#!/bin/bash
# Copyright (c) 2019 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


set -e

(
SCRIPTS=$(cd $(dirname $0) && pwd)
cd $(dirname $0)/..
ROOT=$(pwd)
export ROOT

# shellcheck source=common.sh
. $SCRIPTS/common.sh

GENERATED="src/xr_generated_dispatch_table.c src/xr_generated_dispatch_table.h src/loader/xr_generated_loader.cpp src/loader/xr_generated_loader.hpp"
for fn in $GENERATED; do
    PYTHONPATH=$SPEC_SCRIPTS:$SRC_SCRIPTS python3 "$SRC_SCRIPTS/src_genxr.py" -registry "$REGISTRY" -quiet -o "$(dirname $fn)" "$(basename $fn)"
done

( cd src/external/jsoncpp && python amalgamate.py )

src/combine_headers.py


rm $GENERATED

)
