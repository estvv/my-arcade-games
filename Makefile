##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

BINARY	=	my_snake

CXX	=	g++

CXXFLAGS	=	-I$(INCLUDE) \
				-std=c++17 \
				-lsfml-graphics \
				-lsfml-window \
				-lsfml-system

SRC	=	$(wildcard src/*.cpp)

OBJ	=	$(SRC:.cpp=.o)

INCLUDE	=	include

CFLAGS	=	-I$(INCLUDE) \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lm \
			-g3 \
			-Wall \
			-Werror \
			-Wextra \
			-W

all:	$(BINARY)

$(BINARY):	$(OBJ)
	$(CXX) -o $(BINARY) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(BINARY)

re:	fclean all

.PHONY:	all clean check fclean re
