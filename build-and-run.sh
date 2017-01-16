#!/usr/bin/env bash

set -e

cmake -DCMAKE_BUILD_TYPE=Debug -DWITHCOVERAGE=1 .

cmake --build .
ctest

make coverage

coveralls-lcov --repo-token ${COVERALLS_TOKEN} coverage.info.cleaned
