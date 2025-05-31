NAME			=		test
NAME_X		=		.exe
#
DEBUG			=		-g
#

RAYLIB		=	../../Engine/include/raylib/src/libraylib.a

LINUX_FLAGS	=		-lGL -lm -lrt -lX11
WIN_FLAG		=		-lgdi32 -lwinmm
ENGINE_FLAGS		=		$(RAYLIB) $(WIN_FLAG)

ENGINE_SETTING	=		-Wno-missing-field-initializers

CC				=			cc
CXX				=			g++

CFLAGS		=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra
CXXFLAGS	=			$(DEBUG) $(ENGINE_SETTING) -Wall -Werror -Wextra


# file
CPP_SRCS		=		main.cpp \


CPP_OBJS	=	$(CPP_SRCS:.cpp=.o)




all: $(NAME)

$(NAME) : $(CPP_OBJS)
	$(CXX) $(CFLAGS) $(CPP_OBJS) $(ENGINE_FLAGS) -o $(NAME)

clean:
	@rm -fv $(CPP_OBJS)

fclean: clean
	@rm -fv ../$(NAME)$(NAME_X)

re: fclean all

help:
	@echo make to build
	@echo '>	'help show this message
	@echo '>	'clean to remove all *.o
	@echo '>	'fclean to remove all *.o and .exe