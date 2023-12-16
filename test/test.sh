#!/bin/bash

source test/check.sh

# no arguments
run_test "" "fdf: number of arguments is invalid"

# too many arguments
run_test "map/42.fdf map/42.fdf" "fdf: number of arguments is invalid"

# extension does not exist
run_test "map/error"   "fdf: wrong filename"

# extension does not match .fdf
# 1
run_test "map/42."   "fdf: wrong file extension"

# extension does not match .fdf
# 2
run_test "map/42.f"   "fdf: wrong file extension"

# extension does not match .fdf
# 3
run_test "map/42.fd"   "fdf: wrong file extension"

# extension does not match .fdf
# 4
run_test "map/42.fdfd"   "fdf: wrong file extension"

# hidden file named .fdf
run_test "test/.fdf"   "fdf: wrong filename(.fdf)"

# file does not exist
run_test "map/error/does_not_exist.fdf"   "fdf: No such file or directory"

# empty
# run_test "map/error/empty.fdf"   "fdf: invalid format: not a rectangle map"

# contain invalid charactor as value
run_test "map/error/contain_invalid_charactor_as_value.fdf"   "fdf: invalid file format: invalid charactor"

# not specified color after 0x
run_test "map/error/not_specified_color_after_0x.fdf"   "fdf: invalid file format: invalid charactor"

# contain invalid charactor as color
run_test "map/error/contain_invalid_charactor_as_color.fdf"   "fdf: invalid file format: invalid charactor"

# does not exist 0x before color
run_test "map/error/does_not_exist_0x_before_color.fdf"   "fdf: invalid file format: invalid format"

# not rectangle
run_test "map/error/not_rectangle.fdf"   "fdf: invalid format: not a rectangle map"
