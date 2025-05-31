NAME			=		IceFactory
NAME_X		=		.out
#
DEBUG			=		-g
#

RAYLIB		=	../Engine/include/raylib/src/libraylib.a


LOCAL_LIB	=	$(shell test -e $(RAYLIB) ; echo $$?)

ENGINE_FLAGS		=		$(RAYLIB) -lGL -lm -lrt -lX11

ENGINE_SETTING	=		-D 'HOT_RELOAD=1' -Wno-missing-field-initializers

CC				=			cc
CXX				=			g++

CFLAGS		=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra
CXXFLAGS	=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra

#   --- ENGINE ---
ENGINE		=			../Engine/


BASE				=		$(ENGINE)Base/Base.cpp


CAMERA			=		\
$(ENGINE)Camera/BaseCamera.cpp \
$(ENGINE)Camera/Base2DCamera.cpp


GROUPS			=		$(ENGINE)Groups/BeseGroups.cpp

IMPORT			=		$(ENGINE)Import/

# -- IMPORT -- #
I_MODEL			=		$(IMPORT)Model/ModelManager.cpp

I_AUDIO			=		$(IMPORT)Audio/AudioManager.cpp

I_TEXTURE2D	=		$(IMPORT)Texture2D/Texture2DManager.cpp
# - - - #

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

GAME			=		../Game/
#
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
# -	- - #

#
#


all: buildraylib $(NAME)
	@mv -v $(NAME)$(NAME_X) ..

$(NAME): Engine
	@echo '|' $(NAME)$(NAME_X) '|'

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

# 		Engine/
# 		├── Base
# 		├── Camera
# 		├── Groups
# 		├── Import
# 		│   ├── Model
# 		│   └── Sound
# 		├── include
# 		│   ├── raygui
# 		│   │   ├── examples
# 		│   │   ├── icons
# 		│   │   ├── images
# 		│   │   ├── logo
# 		│   │   ├── projects
# 		│   │   ├── src
# 		│   │   └── styles
# 		│   └── raylib
# 		│       ├── cmake
# 		│       ├── examples
# 		│       ├── logo
# 		│       ├── parser
# 		│       ├── projects
# 		│       └── src
# 		├── Object
# 		├── Render
# 		├── Resource
# 		│   ├── Image
# 		│   ├── Models
# 		│   └── Sound
# 		├── Room
# 		├── Type
# 		└── Ui
# 		
# 32 directories