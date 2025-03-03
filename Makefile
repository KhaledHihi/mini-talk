NAME = server client

SRC = server.c client.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

.PHONY: all clean fclean re
.SECONDARY : $(OBJ) 
