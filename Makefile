NAME = arbuz
FLAGS = -lmlx -lXext -lX11 -lm
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
OBJ = src/main.c \
						src/utils.c \
						src/frac.c 

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)