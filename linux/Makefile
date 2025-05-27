NAME			=		IceFactory
#
DEBUG			=		-g
#

RAYLIB		=	../Engine/include/raylib/src/libraylib.a



LOCAL_LIB	=	$(shell test -e $(RAYLIB) ; echo $$?)

ifeq ($(LOCAL_LIB), 0)
ENGINE_FLAGS		=		$(RAYLIB) -lGL -lm -lrt -lX11
else
ENGINE_FLAGS		=		-lraylib -lGL -lm -lrt -lX11
endif

ENGINE_SETTING	=		-D 'HOT_RELOAD=1' -Wno-error=missing-field-initializers

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

# - - - #

OBJECT			=	\
$(ENGINE)Object/DevCube.cpp		\
$(ENGINE)Object/MeshObject.cpp\
$(ENGINE)Object/Object3D.cpp	\
$(ENGINE)Object/Object2D.cpp	\
$(ENGINE)Object/Object.cpp		\

RENDER			=	$(ENGINE)Render/Render.cpp

ROOM				=	$(ENGINE)Room/Room.cpp

UI					=	\
$(ENGINE)Ui/UiBaseBlock.cpp		\
$(ENGINE)Ui/UiBaseTextBox.cpp	\
$(ENGINE)Ui/UiRenderZone.cpp	\

GAME			=		../Game/
#
GAMEFILE	= $(GAME)main.cpp

# - - - -|-|- - - - #
CPP_SRCS	=		\
	$(BASE)			\
	$(CAMERA)		\
	$(GROUPS)		\
	$(I_MODEL)	\
	$(I_AUDIO)	\
	$(OBJECT)		\
	$(RENDER)		\
	$(ROOM)			\
	$(GAMEFILE)	\
	$(ENGINE)IceFactory.cpp
#$(UI)				\

C_OBJS		=	$(C_SRCS:.c=.o)
CPP_OBJS	=	$(CPP_SRCS:.cpp=.o)
# -	- - #

#
#


all: $(NAME)
	@mv -v $(NAME) ..

$(NAME): Engine
	@echo '|' $(NAME) '|' $(LOCAL_LIB)

Engine: $(CXX)
	@echo

$(CXX): $(CPP_OBJS)
	$(CXX) $(CFLAGS) $(CPP_OBJS) $(ENGINE_FLAGS) -o $(NAME)

$(CPP_OBJS): $(CPP_SRCS)


clean:
	@rm -fv $(CPP_OBJS)

fclean: clean
	@rm -fv ../$(NAME)

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