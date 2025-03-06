NAME = minitalk

SRC = server.c client.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

Libft_DIR = libft/libft.a

Header = mini.h

RM = rm -f

all : $(Libft_DIR) $(NAME) $(Header)

$(NAME):	 server client

server:		server.o
		@make -C libft
		$(CC) $(CFLAGS) $? -Llibft -lft  -o server

client:		client.o
		@make -C libft
		$(CC) $(CFLAGS) $? -Llibft -lft  -o client

bonus : all

$(Libft_DIR) :
	@$(MAKE) -C libft

re : fclean all

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) server client
	@$(MAKE) -C libft fclean

.PHONY: all clean fclean re
.SECONDARY : $(OBJ)
