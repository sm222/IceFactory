#!/bin/env bash

# color
RED=\\x1B[31m
GRN=\\x1B[32m
YEL=\\x1B[33m
BLU=\\x1B[34m
MAG=\\x1B[35m
CYN=\\x1B[36m
WHT=\\x1B[37m
RESET=\\x1B[0m

################################
#
#          Setting
#
################################

raylibPath='../Engine/include/raylib/src/libraylib.a'

buildTime=$(bash -c date)
platform=$(bash -c uname -os)
madeby='@sm222'

sysHeader=(
  '########################################'
  '#	made by'
  "#		$madeby"
  "#		$buildTime"
  "#		$platform"
  '#'
  "#	Don't edit that file by hands,"
  "#		call $0"
  '#		and edit the variable in varAndFiles'
  '########################################'
)

i_sysHeader=${#sysHeader[@]}

function printSysHeader() {
  echo -n
  j_sysHeader=0
  while [ $j_sysHeader -lt $i_sysHeader ]
  do
    echo "${sysHeader[$j_sysHeader]}" >> $1
    j_sysHeader=$((j_sysHeader + 1))
  done
}


################################
#
#          C/C++
#
################################

compiler=(
  ''
  ''
  '#  compiler'
  'CC				=		cc'
  'CXX			=			g++'
  ''
  ''
  ''
  '#  flags'
  'CFLAGS		=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra'
  'CXXFLAGS	=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra'
  ''
)

i_compiler=${#compiler[@]}

function drawCompiler() {
  j_compiler=0
  echo -n
  while [ $j_compiler -lt $i_compiler ]
  do
    echo "${compiler[$j_compiler]}" >> $1
    j_compiler=$((j_compiler + 1))
  done
}


################################
#
#          Engine
#
################################

varAndFiles=(
  '#	engine root'
  'ENGINE		=			../Engine/'
  ''
  '#	Base'
  ''
  'BASE				=		$(ENGINE)Base/Base.cpp'
  ''
  '# -- Object -- #'
  'OBJECT		=		$(ENGINE)Object/'
  ''
  '# object'
  ''
  'OBJECTCPP	=	$(OBJECT)obj.cpp'
  ''
  '# object3D'
  'OBJECT3D		=		$(OBJECT)3D/'
  ''
  'OBJECT3DCPP	=	$(OBJECT3D)obj3D.cpp'
  ''
  '# camera3D'
  'CAMERA3D	=	$(OBJECT3D)3DCamera/3DCamera.cpp'
  ''
  '# -- IMPORT -- #'
  ''
  'IMPORT			=		$(ENGINE)Import/'
  ''
  'I_MODEL			=		$(IMPORT)Model/ModelManager.cpp'
  ''
  'I_AUDIO			=		$(IMPORT)Audio/AudioManager.cpp'
  ''
  'I_TEXTURE2D	=		$(IMPORT)Texture2D/Texture2DManager.cpp'
  ''
  '#  --  --  --  #'
  ''
  ''
  'UI					=	\'
  '$(ENGINE)Ui/UiBaseBlock.cpp		\'
  '$(ENGINE)Ui/UiBaseTextBox.cpp	\'
  '$(ENGINE)Ui/UiRenderZone.cpp	\'
  ''
)


i_varAndFiles=${#varAndFiles[@]}

function printFiles() {
  echo -n
  j_varAndFiles=0
  while [ $j_varAndFiles -lt $i_varAndFiles ]
  do
    echo "${varAndFiles[$j_varAndFiles]}" >> $1
    j_varAndFiles=$((j_varAndFiles + 1))
  done
}

################################
#
#          Game
#
################################

gameFiles=(
  ''
  '# Game root'
  'GAME			=		../Game/'
  ''
  'GAMEFILE	= $(GAME)main.cpp'
  ''
  ''
)

i_gameFiles=${#gameFiles[@]}

function printGameFiles() {
  echo -n
  j_gameFiles=0
  while [ $j_gameFiles -lt $i_gameFiles ]
  do
    echo "${gameFiles[$j_gameFiles]}" >> $1
    j_gameFiles=$((j_gameFiles + 1))
  done
}


################################
#
#          compile rule
#
################################

compileRule=(
  ''
  '# - - - -|-|- - - - #'
  'CPP_SRCS	=					\'
  '$(BASE)						\'
  '$(OBJECTCPP)				\'
  '$(OBJECT3DCPP)			\'
  '$(CAMERA3D)				\'
  '$(I_MODEL)					\'
  '$(I_AUDIO)					\'
  '$(I_TEXTURE2D)			\'
  '$(GAMEFILE)				\'
  '$(ENGINE)IceFactory.cpp'
  '#$(UI)				\'
  ''
  ''
  'C_OBJS		=	$(C_SRCS:.c=.o)'
  'CPP_OBJS	=	$(CPP_SRCS:.cpp=.o)'
  ''
  ''
  'all: buildraylib $(NAME)'
  '	@mv -v $(NAME)$(NAME_X) ..'
  ''
  '$(NAME): Engine'
  '	@echo "| $(NAME)$(NAME_X) |"'
  ''
  'Engine: $(CXX)'
  '	@echo'
  ''
  '$(CXX): $(CPP_OBJS)'
  '	$(CXX) $(CFLAGS) $(CPP_OBJS) $(ENGINE_FLAGS) -o $(NAME)$(NAME_X)'
  ''
  buildraylib:
  '	make -C ../Engine/include/raylib/src/'
  ''
  clean:
  '	@rm -fv $(CPP_OBJS)'
  ''
  'fclean: clean'
  '	@rm -fv ../$(NAME)$(NAME_X)'
  ''
  're: fclean all'
  ''
  '.PHONY: Engine'
)

i_compileRule=${#compileRule[@]}

function printCompileRule() {
  echo -n
  j_compileRule=0
  while [ $j_compileRule -lt $i_compileRule ]
  do
    echo "${compileRule[$j_compileRule]}" >> $1
    j_compileRule=$((j_compileRule + 1))
  done
}

################################
#
#          Linux
#
################################

linuxHeader=(
  ''
  '# Linux MAKEFILE'
  'NAME			=			IceFactory'
  'NAME_X		=			.out'
  ''
  '# - - - -'
  ''
  "RAYLIB		=		$raylibPath"
  'ENGINE_FLAGS		=		$(RAYLIB) -lGL -lm -lrt -lX11'
  'ENGINE_SETTING	=		-D 'HOT_RELOAD=1' -Wno-missing-field-initializers'
  ''
  'DEBUG						=		-g'
  ''
)

i_linuxHeader=${#linuxHeader[@]}

linuxFilename=../linux/Makefile

function makelinux() {
  j_linuxHeader=0
  rm -f $linuxFilename
  printf $GRN"making $linuxFilename$RESET\n"
  touch $linuxFilename
  printSysHeader $linuxFilename
  while [ $j_linuxHeader -lt $i_linuxHeader ]
  do
    echo "${linuxHeader[$j_linuxHeader]}" >> $linuxFilename
    j_linuxHeader=$((j_linuxHeader + 1))
  done
  drawCompiler $linuxFilename
  printFiles $linuxFilename
  printGameFiles $linuxFilename
  printCompileRule $linuxFilename
}


################################
#
#          Windows
#
################################

winHeader=(
  ''
  '# WINDOS MAKEFILE'
  'NAME			=			IceFactory'
  'NAME_X		=			.exe'
  ''
  '# - - - -'
  ''
  "RAYLIB		=		$raylibPath"
  'ENGINE_FLAGS		=		$(RAYLIB) -lgdi32 -lwinmm'
  'ENGINE_SETTING	=		-D 'HOT_RELOAD=1' -Wno-missing-field-initializers'
  ''
  'DEBUG						=		-g'
  ''
)

i_winHeader=${#winHeader[@]}

WindowsFilename=../windows/Makefile

function makeWindos() {
  j_winHeader=0
  rm -f $WindowsFilename
  printf $GRN"making $WindowsFilename$RESET\n"
  touch $WindowsFilename
  printSysHeader $WindowsFilename
  while [ $j_winHeader -lt $i_winHeader ]
  do
    echo "${winHeader[$j_winHeader]}" >> $WindowsFilename
    j_winHeader=$((j_winHeader + 1))
  done
  drawCompiler $WindowsFilename
  printFiles $WindowsFilename
  printGameFiles $WindowsFilename
  printCompileRule $WindowsFilename
}

function makeFolder() {
  mkdir ../linux
  mkdir ../windows
}


time makelinux
printf "\n"$BLU"done$RESET\n"
time makeWindos
printf "\n"$BLU"done$RESET\n"
