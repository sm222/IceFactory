#!/bin/sh
projectDir=IceFactory
var=$(which bear)
mkdir -p ../build/
test -x "$var" && $var --output ../build/compile_commands.json -- make && exit
echo error $?
