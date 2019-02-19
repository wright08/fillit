#!/usr/bin/make -f

NAME = fillit
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += #-Ofast
CFLAGS += #-g -fsanitize=address
INC = -I fillit -I libft
LIB = -L lib -lft
SRC_DIR = src
OBJ_DIR = obj

SRC = \
	   test

OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
