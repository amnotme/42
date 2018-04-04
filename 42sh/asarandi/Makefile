NAME		= minishell
SRC			= main.c
OBJ			= $(SRC:%.c=%.o)
CC			= gcc
FLAGS		= -g -Wextra -Wall -Werror # -fsanitize=address
INC			= -I libft/ -I libft/ft_printf/
LIB			= -L libft/ -lft -L libft/ft_printf/ -lftprintf

all:$(NAME)

$(NAME):
	make -C libft/
	make -C libft/ft_printf/
	$(CC) $(FLAGS) $(INC) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

rmobj:
	rm -f $(OBJ)

rmbin:
	rm -f $(NAME)

again: rmobj rmbin all

clean: rmobj
	make clean -C libft/
	make clean -C libft/ft_printf/

fclean: clean rmbin
	make fclean -C libft/
	make fclean -C libft/ft_printf/

re: fclean all
