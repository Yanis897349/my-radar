##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Build my_radar
##

CC = gcc
CFLAGS = -Wall -Wextra -I. -I./src/ -MMD -MP

LDFLAGS = -L .
CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
LDLIBS = -lm -lmy $(CSFMLFLAGS)

RM = rm -f

MAIN_SRC = ./src/main.c
SRC = ./src/Screen/screen.c \
	./src/Simulation/simulation.c \
	./src/Simulation/world.c \
	./src/Simulation/tower.c \
	./src/Simulation/aircraft.c \
	./src/Simulation/Events/event_handler.c \
	./src/Parser/reader.c \
	./src/Parser/parser.c \
	./src/Simulation/quadtree.c
SRC_TEST = ./tests/test.c
OBJS = $(MAIN_SRC:.c=.o) $(SRC:.c=.o)
TEST_OBJS = $(SRC:.c=.o) $(SRC_TEST:.c=.o)

LIB_PATH = ./lib/my

NAME_TEST = unit_tests
NAME := my_radar

.PHONY: all build_lib clean_lib fclean_lib clean fclean re tests_run \
	tests_clean

all: $(NAME)

$(NAME): build_lib $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(NAME_TEST): build_lib $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $(NAME_TEST) $(LDFLAGS) $(LDLIBS) \
	--coverage -lcriterion

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

build_lib:
	make -C $(LIB_PATH)

clean_lib:
	make clean -C $(LIB_PATH)

fclean_lib:
	make fclean -C $(LIB_PATH)

clean: clean_lib
	find . -type f \( -name '*.o' -o -name '*.d' \) -delete

fclean: clean fclean_lib
	$(RM) $(NAME)

re: fclean all

tests_run: $(NAME_TEST)
	./$(NAME_TEST)

tests_clean:
	$(RM) $(NAME_TEST)
	$(RM) *.gcno *.gcda

# Include the dependency files generated by GCC
-include $(OBJS:.o=.d) $(TEST_OBJS:.o=.d)
