#!/bin/sh

dir="linux"
rayLibGit="https://github.com/raysan5/raylib.git"
logFile="log.txt"

cd $dir && echo 'cd' $dir
touch $logFile && echo "building" > $logFile
echo "building"

#T="$(ls -1)"

#look for missing lib
ray="$(ls ../Engine/include | grep raylib)"
test -z $ray && git clone $rayLibGit && mv raylib ../Engine/include/

make -C ../Engine/include/raylib/src

make