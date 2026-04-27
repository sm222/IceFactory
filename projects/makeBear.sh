#!/bin/env sh
set -e

bear=$(which bear)
mkdir -p ../build/
test -x "$bear" && $bear --output ../build/compile_commands.json -- make && exit
echo error $?
