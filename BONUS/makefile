LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIE -g

SRC = pipex_bonus.c pathfinder_bonus.c split2.c utils_bonus.c bool_utils.c pathfinding_utils.c heredoc_utils.c
OBJ = $(SRC:.c=.o)

NAME = pipex

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) ${OBJ_BONUS}

fclean: clean
	rm -f $(NAME) 
	make -C $(LIBFT_DIR) fclean

re: fclean all