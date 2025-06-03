########################################
#	made by
#		@sm222
#		Tue 03 Jun 2025 12:37:06 AM EDT
#		Linux
#
#	Don't edit that file by hands,
#		call ./buildMakefile.sh
#		and edit the variable in varAndFiles
########################################

# Linux MAKEFILE
NAME			=			IceFactory
NAME_X		=			.out

# - - - -

RAYLIB		=		../Engine/include/raylib/src/libraylib.a
ENGINE_FLAGS		=		$(RAYLIB) -lGL -lm -lrt -lX11
ENGINE_SETTING	=		-D HOT_RELOAD=1 -Wno-missing-field-initializers

DEBUG						=		-g



#  compiler
CC				=		cc
CXX			=			g++



#  flags
CFLAGS		=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra
CXXFLAGS	=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra

#	engine root
ENGINE		=			../Engine/

#	Base

BASE				=		$(ENGINE)Base/Base.cpp


CAMERA			=		\
$(ENGINE)Camera/BaseCamera.cpp \
$(ENGINE)Camera/Base2DCamera.cpp

#Group
GROUPS			=		$(ENGINE)Groups/BeseGroups.cpp


#

# -- IMPORT -- #

IMPORT			=		$(ENGINE)Import/

I_MODEL			=		$(IMPORT)Model/ModelManager.cpp

I_AUDIO			=		$(IMPORT)Audio/AudioManager.cpp

I_TEXTURE2D	=		$(IMPORT)Texture2D/Texture2DManager.cpp

#  --  --  --  #


OBJECT			=	\
$(ENGINE)Object/DevCube.cpp		\
$(ENGINE)Object/MeshObject.cpp\
$(ENGINE)Object/Object3D.cpp	\
$(ENGINE)Object/Object2D.cpp	\
$(ENGINE)Object/Object.cpp		\


RENDER			=	$(ENGINE)Render/Render.cpp

DRAW2D			=	$(ENGINE)Draw2D/DrawTexture2D.cpp

ROOM				=	$(ENGINE)Room/Room.cpp


UI					=	\
$(ENGINE)Ui/UiBaseBlock.cpp		\
$(ENGINE)Ui/UiBaseTextBox.cpp	\
$(ENGINE)Ui/UiRenderZone.cpp	\


# Game root
GAME			=		../Game/

GAMEFILE	= $(GAME)main.cpp



# - - - -|-|- - - - #
CPP_SRCS	=				\
$(BASE)					\
$(CAMERA)				\
$(GROUPS)				\
$(I_MODEL)			\
$(I_AUDIO)			\
$(I_TEXTURE2D)	\
$(OBJECT)				\
$(RENDER)				\
$(DRAW2D)				\
$(ROOM)					\
$(GAMEFILE)			\
$(ENGINE)IceFactory.cpp
#$(UI)				\


C_OBJS		=	$(C_SRCS:.c=.o)
CPP_OBJS	=	$(CPP_SRCS:.cpp=.o)


all: buildraylib $(NAME)
	@mv -v $(NAME)$(NAME_X) ..

$(NAME): Engine
	@echo "| $(NAME)$(NAME_X) |"

Engine: $(CXX)
	@echo

$(CXX): $(CPP_OBJS)
	$(CXX) $(CFLAGS) $(CPP_OBJS) $(ENGINE_FLAGS) -o $(NAME)$(NAME_X)

buildraylib:
	make -C ../Engine/include/raylib/src/

clean:
	@rm -fv $(CPP_OBJS)

fclean: clean
	@rm -fv ../$(NAME)$(NAME_X)

re: fclean all

.PHONY: Engine
