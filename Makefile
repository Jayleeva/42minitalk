NAME_SERVER = server
NAME_CLIENT = client
LIBFT = libft
LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/$(LIBFT)

SRC_DIR = ./src
SRC_SERVER = server.c
SRC_CLIENT = client.c is_int.c
SRC_SERVER := $(addprefix $(SRC_DIR)/, $(SRC_SERVER))
SRC_CLIENT := $(addprefix $(SRC_DIR)/, $(SRC_CLIENT))

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./inc -I ./libft/inc

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT_LIB)
	@${CC} ${CFLAGS} ${OBJ_SERVER} $(LIBFT_LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT_LIB)
	@${CC} ${CFLAGS} ${OBJ_CLIENT} $(LIBFT_LIB) -o $(NAME_CLIENT)

$(LIBFT_LIB):
	@${MAKE} -C libft

clean:
	@${MAKE} -C libft fclean
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
re: fclean all

.PHONY : all clean fclean re