#!/bin/bash

source test/check.sh

exit_status=0

run_test_check_status() {
    local args="$1"
    local expected_output="$2"

    result=$(run_test "$args" "$expected_output")
    if [ $? == 1 ]; then
        exit_status=1
    fi
}

# no arguments
run_test_check_status "" "fdf: number of arguments is invalid"

# too many arguments
run_test_check_status "map/42.fdf map/42.fdf" "fdf: number of arguments is invalid"

# extension does not exist
run_test_check_status "map/error" "fdf: wrong filename"

# extension does not match .fdf
run_test_check_status "map/42." "fdf: wrong file extension"
run_test_check_status "map/42.f" "fdf: wrong file extension"
run_test_check_status "map/42.fd" "fdf: wrong file extension"
run_test_check_status "map/42.fdfd" "fdf: wrong file extension"

# hidden file named .fdf
run_test_check_status "test/.fdf" "fdf: wrong filename(.fdf)"

# file does not exist
run_test_check_status "map/error/does_not_exist.fdf" "fdf: No such file or directory"

# contain invalid character as value
run_test_check_status "map/error/contain_invalid_charactor_as_value.fdf" "fdf: invalid file format: invalid charactor"

# not specified color after 0x
run_test_check_status "map/error/not_specified_color_after_0x.fdf" "fdf: invalid file format: invalid charactor"

# contain invalid character as color
run_test_check_status "map/error/contain_invalid_charactor_as_color.fdf" "fdf: invalid file format: invalid charactor"

# does not exist 0x before color
run_test_check_status "map/error/does_not_exist_0x_before_color.fdf" "fdf: invalid file format: invalid format"

# not rectangle
run_test_check_status "map/error/not_rectangle.fdf" "fdf: invalid format: not a rectangle map"

exit $exit_status
