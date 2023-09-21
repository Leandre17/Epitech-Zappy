##
## EPITECH PROJECT, 2023
## B-YEP-400-BDX-4-1-zappy-johanna.bureau
## File description:
## Makefile for the Zappy server
##

NAME				= 			zappy_server
TEST_NAME			=			unit_tests

SRC_MAIN			=			$(addprefix src/,							\
									main.c									\
								)

SRC					=			$(addprefix src/,							\
									broadcasting/angles.c					\
									broadcasting/output.c					\
									broadcasting/points.c					\
									broadcasting/tile.c						\
									commands/ai/broadcast.c					\
									commands/ai/connect_nbr.c				\
									commands/ai/eject.c						\
									commands/ai/fork.c						\
									commands/ai/forward.c					\
									commands/ai/incantation.c				\
									commands/ai/inventory.c					\
									commands/ai/left.c						\
									commands/ai/look.c						\
									commands/ai/no_team.c					\
									commands/ai/right.c						\
									commands/ai/set.c						\
									commands/ai/take.c						\
									commands/graphic/bct.c					\
									commands/graphic/graphic.c				\
									commands/graphic/mct.c					\
									commands/graphic/msz.c					\
									commands/graphic/pin.c					\
									commands/graphic/plv.c					\
									commands/graphic/ppo.c					\
									commands/graphic/sgt.c					\
									commands/graphic/sst.c					\
									commands/graphic/tna.c					\
									commands/command_manager.c				\
									commands/handler.c						\
									commands/log.c							\
									debug/config.c							\
									debug/map.c								\
									destroy/config.c						\
									destroy/data.c							\
									destroy/map.c							\
									destroy/player.c						\
									destroy/server.c						\
									destroy/teams.c							\
									egg/add.c								\
									egg/handler.c							\
									egg/remove.c							\
									incantation/add.c						\
									incantation/handler.c					\
									incantation/remove.c					\
									incantation/requirements.c				\
									incantation/send.c						\
									incantation/update_players.c			\
									init/config/set_values.c				\
									init/config/set_values2.c				\
									init/config.c							\
									init/fd_set.c							\
									init/fill_map.c							\
									init/map.c								\
									init/player.c							\
									init/server.c							\
									init/teams.c							\
									logs/bct.c								\
									logs/ebo.c								\
									logs/edi.c								\
									logs/enw.c								\
									logs/pbc.c								\
									logs/pdi.c								\
									logs/pdr.c								\
									logs/pex.c								\
									logs/pfk.c								\
									logs/pgt.c								\
									logs/pic.c								\
									logs/pie.c								\
									logs/pin.c								\
									logs/pnw.c								\
									logs/ppo.c								\
									tools/angles.c							\
									tools/args.c							\
									tools/crlf.c							\
									tools/error.c							\
									tools/getnbr.c							\
									tools/lib.c								\
									tools/msprintf.c						\
									tools/parsing.c							\
									tools/pos.c								\
									tools/read_from_fd.c					\
									tools/send.c							\
									tools/socket.c							\
									tools/time.c							\
									tools/usage.c							\
									tools/write_to_fd.c						\
									client.c								\
									connection.c							\
									loop.c									\
									player.c								\
									players.c								\
									resources.c								\
									resources2.c							\
									teams.c									\
									tile.c									\
									tile2.c									\
									win.c									\
									zappy_server.c							\
								)

SRC_TESTS			=			$(addprefix tests/,							\
									ai_commands/test_forward.c				\
									ai_commands/test_left.c					\
									ai_commands/test_right.c				\
									graphics_commands/test_msz.c			\
									graphics_commands/test_tna.c			\
									utils/globals.c							\
									utils/send_receive.c					\
									utils/setup.c							\
									utils/teardown.c						\
								)

SRC_TESTS			+=			$(SRC)

OBJ_MAIN			=			$(SRC_MAIN:.c=.o)
OBJ					=			$(SRC:.c=.o)
OBJ_TESTS			=			$(SRC_TESTS:.c=.o)

CC					=			gcc
LIBS				=			-lm
RM					=			rm -f
INCLUDES			=			-Iinclude -Itests/include
CFLAGS				+=			$(INCLUDES) -lm -Wall -Wextra -Werror
CRITERION			=			--coverage -lcriterion

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) $(LIBS) -o $(NAME) $(OBJ_MAIN) $(OBJ)

tests_run: $(OBJ_TESTS)
	$(CC) $(CRITERION) -o $(TEST_NAME) $(OBJ_TESTS)
	./$(TEST_NAME)

cover:
	gcovr --exclude tests/
	gcovr --branches --exclude tests/

my_tests: tests_run cover fclean

clean:
	$(RM) $(OBJ_MAIN) $(OBJ) $(OBJ_TESTS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re: fclean all

.PHONY: all $(NAME) tests_run cover my_tests clean fclean re
