#!/bin/bash

UNAME=$(uname)

if [ $(UNAME) = "Darwin" ]; then echo "macOS です。libmlx.dylib をカレントディレクトリにコピーします。"; fi
