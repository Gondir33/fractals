NAME = fract-ol

FLAGS = -lmlx -lXext -lX11 -lm

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLD = includes/

SRC = src/main.c \
						src/utils.c \
						src/frac.c 

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) 
	$(CC) $^ -o $@ $(CFLAGS) $(FLAGS) -o $(NAME)

%.o: %.c  includes/fractol.h $(SRC)
	$(CC) $(CFLAGS) $(FLAGS) -I $(INCLD) -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)

re: fclean  all