#!/usr/bin/env bash

set -e

find . \( -name CMakeFiles -o -name CMakeCache.txt \) -exec rm -rf {} \;

cmake -DCMAKE_BUILD_TYPE=Debug -DWITHCOVERAGE=1 .

cmake --build .
ctest

make coverage
