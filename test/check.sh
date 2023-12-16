#!/bin/bash

PROGRAM="./fdf"
EXPECTED_EXIT_STATUS=1

run_test() {
    local args="$1"
    local expected_output="$2"

    $PROGRAM $args
    EXIT_STATUS=$?

    if [ $EXIT_STATUS -ne $EXPECTED_EXIT_STATUS ]; then
        echo "exit status: fail test"
        exit 1
    fi

    ACTUAL_OUTPUT=$($PROGRAM $args 2>&1)

    if [ "$ACTUAL_OUTPUT" != "$expected_output" ]; then
        echo "output: fail test"
        exit 1
    fi

    echo "test passed"
}

if [ "$0" = "$BASH_SOURCE" ]; then
    echo "this file does not execute directly."
    exit 1
fi
