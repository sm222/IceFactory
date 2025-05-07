NANE			=		IceFactory
#
DEBUG			=		-g
#
CFLAGS		=		-Wall -Werror -Wextra
CC				=		 cc
CXX				=		 g++

#   --- ENGINE ---
ENGINE	=			../Engine/

BASE				=		$(ENGINE)Base/Base.cpp

CAMERA			=		$(ENGINE)Camera/BaseCamera.cpp

GROUPS			=		$(ENGINE)Groups/BeseGroups.cpp

IMPORT			=		$(ENGINE)Import/

# -- IMPORT -- #
I_MODEL			=		$(IMPORT)Model/ModelManager.cpp

# - - - #

OBJECT			=	\
$(ENGINE)Object/DevCube.cpp		\
$(ENGINE)Object/MeshObject.cpp\
$(ENGINE)Object/Object3D.cpp	\
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
	$(OBJECT)		\
	$(RENDER)		\
	$(ROOM)			\
	$(UI)				\
	$(GAMEFILE)	\
	$(ENGINE)IceFactory.cpp

C_OBJS		=	$(C_SRCS:.c=.o)
CPP_OBJS	=	$(CPP_SRCS:.cpp=.o)

#
RAYLIB		=	../Engine/include/raylib/src/libraylib.a
#

HOT_RELOAD	=	0
ifeq ($(HOT_RELOAD), 0)
ENGINE_FLAGS	=		$(RAYLIB) -lGL -lm -lrt -lX11 -o
else
ENGINE_FLAGS	=	-D HOT_RELOAD=1	-lraylib	-lGL -lm -lrt -lX11 -o
endif

all: Engine
	mv $(NANE) ..

Engine:
	$(info building engine)
	$(CXX) $(DEBUG) $(CFLAGS) $(CPP_SRCS) $(ENGINE_FLAGS) $(NANE)

clear:
	@rm -vf *.o

.PHONY: Engine