SRC = 	./main.c \
		./ft_check_map.c \
		./ft_strlen.c \
		./ft_atoi.c \
		./ft_strdup.c \
		./ft_print_map.c

NAME = bsq

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = bsq.h

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	${CC} -c -o $@ $< ${CFLAGS}

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re