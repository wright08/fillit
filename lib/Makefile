#usr/bin/make -f

NAME = libft.a
AR = ar
ARFLAGS = -rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ_DIR = obj

#	CTYPES
SRC = \
	  ft_isalnum\
	  ft_isalpha\
	  ft_isascii\
	  ft_isdigit\
	  ft_isprint\
	  ft_isspace\
	  ft_toupper\
	  ft_tolower

#	STDLIB
SRC += \
	  ft_atoi

#	STRING
SRC += \
	  ft_bzero\
	  ft_memchr\
	  ft_memcmp\
	  ft_memcpy\
	  ft_memccpy\
	  ft_memmove\
	  ft_memset\
	  ft_strcat\
	  ft_strlcat\
	  ft_strncat\
	  ft_strchr\
	  ft_strrchr\
	  ft_strcmp\
	  ft_strncmp\
	  ft_strcpy\
	  ft_strlcpy\
	  ft_strncpy\
	  ft_strdup\
	  ft_strstr\
	  ft_strnstr

#	SHITTY PRINTF
SRC += \
	  ft_putchar\
	  ft_putchar_fd\
	  ft_putendl\
	  ft_putendl_fd\
	  ft_putnbr\
	  ft_putnbr_fd\
	  ft_putstr\
	  ft_putstr_fd

#	STRINGS/MEM
SRC += \
	  ft_itoa\
	  ft_memalloc\
	  ft_memdel\
	  ft_strclr\
	  ft_strdel\
	  ft_strequ\
	  ft_striter\
	  ft_striteri\
	  ft_strjoin\
	  ft_strlen\
	  ft_strmap\
	  ft_strmapi\
	  ft_strnequ\
	  ft_strnew\
	  ft_strsplit\
	  ft_strsub\
	  ft_strtrim

#	LIST
SRC += \
	  ft_lstadd\
	  ft_lstdel\
	  ft_lstdelone\
	  ft_lstiter\
	  ft_lstmap\
	  ft_lstnew

#	VECTOR
SRC += \
	   vector_add\
	   vector_delete\
	   vector_free\
	   vector_get\
	   vector_new\
	   vector_resize\
	   vector_set

# GET_NEXT_LINE
SRC += get_next_line

OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $(OBJ)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
