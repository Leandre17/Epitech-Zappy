##
## EPITECH PROJECT, 2023
## B-YEP-400-BDX-4-1-zappy-johanna.bureau
## File description:
## Makefile
##

NAME 				= 			zappy_gui

SRC_MAIN			=			$(addprefix src/,							\
									Client.cpp								\
									main.cpp								\
									Params.cpp								\
									TileMap.cpp								\
									Sprite.cpp								\
									Commands.cpp							\
									Rocks.cpp								\
									Ressources.cpp							\
									Popup.cpp								\
									Broadcast.cpp							\
									Display.cpp								\
									Menu.cpp								\
									SpriteMove.cpp							\
									AnimMove.cpp							\
									Pokemon.cpp								\
									Eggs.cpp								\
								)

SRC					=			$(addprefix src/,							\
								)

OBJ_MAIN			=			$(SRC_MAIN:.cpp=.o)
OBJ					=			$(SRC:.cpp=.o)

CC					=			g++
RM					=			rm -f
CPPFLAGS			=			-Iinclude -Wall -Wextra -std=c++20 -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window

all:	$(NAME)

$(NAME): $(OBJ_MAIN) $(OBJ)
	$(CC) -o $(NAME) $(OBJ_MAIN) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ_MAIN) $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

debug: fclean
debug: CPPFLAGS += -ggdb3
debug: all

.PHONY: all clean fclean re debug
