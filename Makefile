NAME = minitalk

SRC = server.c client.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

Libft_DIR = lib_ft/libft.a

Header = mini.h

RM = rm -f

all : $(Libft_DIR) $(NAME) $(Header)

$(NAME):	 server client

server:		server.o
		@make -C lib_ft
		$(CC) $(CFLAGS) $? -Llib_ft -lft  -o server

client:		client.o
		@make -C lib_ft
		$(CC) $(CFLAGS) $? -Llib_ft -lft  -o client

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus : all

$(Libft_DIR) :
	@$(MAKE) -C lib_ft

re : fclean all

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C lib_ft clean

fclean: clean
	@$(RM) server client
	@$(MAKE) -C lib_ft fclean

.PHONY: all clean fclean re
.SECONDARY : $(OBJ)
