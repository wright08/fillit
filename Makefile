#!/usr/bin/make -f

NAME = fillit
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += #-Ofast
CFLAGS += #-g -fsanitize=address
INC = -I src -I lib
LIB = -L lib -lft
SRC_DIR = src
OBJ_DIR = obj
TEST_SRC = tests
TEST_OBJ = tests/obj

SRC = \
	  fillit\
	  parse

TEST = \
	   parse

OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

OBJ_TEST = $(patsubst %, $(TEST_OBJ)/%.o, $(TEST))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

test: $(NAME) $(OBJ_TEST)
	@$(CC) $(filter-out %$(NAME).o, $(OBJ)) $(OBJ_TEST) $(LIB) -o $@

$(TEST_OBJ)/%.o: $(TEST_SRC)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

tclean:
	@rm -f test
	@rm -rf $(TEST_OBJ)

re: fclean all
