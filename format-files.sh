#!/bin/sh
find -iname "*.h" -o -iname "*.c" -o -iname "*.cp" -o -iname "*.cpp" src include | xargs clang-format -i
