#!/bin/env sh

# safety/ break on error
set -e

path='../thirdParty'
raylib='https://github.com/raysan5/raylib.git'

mkdir $path && echo 'making' $path
cd $path && echo 'moving to' $path
git clone $raylib && echo 'clonig done'
cd raylib/src && make -j10
echo 'done ready to go'
exit 0