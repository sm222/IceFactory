#!/bin/bash

# color
RED=\\x1B[31m
GRN=\\x1B[32m
YEL=\\x1B[33m
BLU=\\x1B[34m
MAG=\\x1B[35m
CYN=\\x1B[36m
WHT=\\x1B[37m
RESET=\\x1B[0m

buildTime=$(bash -c date)
platform=$(bash -c uname -os)
madeby='@sm222'

sysHeder=(
  '# made by'
  "#		$madeby"
  "#		$buildTime"
  "#		$platform"
  '# - - - - - -  -'
)

i_sysHeader=${#sysHeder[@]}
j_sysHeader=0

function printSysHeader() {
  echo -n
  while [ $j_sysHeader -lt $i_sysHeader ]
  do
    echo "${sysHeder[$j_sysHeader]}" >> $1
    j_sysHeader=$((j_sysHeader + 1))
  done
}

#
winHeader=(
  ''
  ''
  ''
  '# WINDOS MAKEFILE '
  'NAME			= IceFactory'
  'NAME_X		= .exe'
  ''
  '# - - - -'
  ''
  'RAYLIB		=	../Engine/include/raylib/src/libraylib.a'
  'ENGINE_FLAGS		=		$(RAYLIB) -lgdi32 -lwinmm'
  'ENGINE_SETTING	=		-D 'HOT_RELOAD=1' -Wno-missing-field-initializers'
  'DEBUG						=		-g'
)

normalHeader=(
  ''
  ''
  '#  compiler'
  'CC				=			cc'
  'CXX			=			g++'
  ''
  ''
  ''
  '#  flags'
  'CFLAGS		=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra'
  'CXXFLAGS	=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra'
  ''

)

varAndFiles=(
  ""
)


linuxFilename=makeFileLinux

function makelinux() {
  rm -fv $linuxFilename
  echo 'touch' $linuxFilename
  touch $linuxFilename
  while [ $j -lt $i ]
  do
    echo "${varAndFiles[$j]}" >> $linuxFilename
    j=$((j + 1))
  done
}

WindowsFilename=makeFileWindows

i_winHeader=${#winHeader[@]}
j_winHeader=0

function makeWindos() {
  rm -fv $WindowsFilename
  echo 'touch' $WindowsFilename
  touch $WindowsFilename
  printSysHeader $WindowsFilename
  while [ $j_winHeader -lt $i_winHeader ]
  do
    echo "${winHeader[$j_winHeader]}" >> $WindowsFilename
    j_winHeader=$((j_winHeader + 1))
  done
}

makeWindos