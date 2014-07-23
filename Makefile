NAME = bsq

CFLAGS = -Wall -Werror -Wextra -O3 -g

FILES = main.c\
		libft_0.c\
		calculus.c\
		parse.c\


SRC = $(addprefix src/, $(FILES))
OBJ = $(SRC:src/%.c=obj/%.o)

CFLAGS += -Iinclude/

.PHONY: all clean fclean re dirobj

.SILENT: dirobj

all: dirobj $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

obj/%.o : src/%.c
		$(CC) -o $@ -c $^ $(CFLAGS)

clean:
		rm -rf obj

fclean: clean
		rm -f $(NAME)

re: fclean all

dirobj:
		mkdir -p obj
