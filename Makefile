##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

BINARY		=	my_snake
CXX			=	g++
SRC_DIR		=	src
SRC_FILES	=	$(shell find $(SRC_DIR) -name "*.cpp")
OBJ			=	$(SRC:.cpp=.o)
INCLUDE		=	include
CXXFLAGS	=	-I$(INCLUDE) -g3 -Wall -Werror -Wextra
LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -lm

all:	$(BINARY)

$(BINARY): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(BINARY)

re:	fclean all

.PHONY:	all clean check fclean re
