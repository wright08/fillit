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

SRC = \
	  fillit

OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

test: $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
