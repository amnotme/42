# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztisnes <ztisnes@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 17:50:25 by ztisnes           #+#    #+#              #
#    Updated: 2018/03/25 17:50:52 by ztisnes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=exe
SRC=*.c

FLAGS=-Wextra -Wall -Werror -g

LIBFT=./libft
LIBFTFT_PRINTF=./ft_printf
LIBFT_LS=./ft_ls

LIBFT_NAME=libft
LIBFTFT_PRINTF_NAME=libftprintf
LIBFT_LS_NAME=libftls


all:$(NAME)

$(NAME):
	@cd $(LIBFT) && make
	@cd $(LIBFTFT_PRINTF) && make
	@cd $(LIBFT_LS) && make

	@gcc -c $(SRC) $(FLAGS)
	@gcc $(SRC:.c=.o) -o $(NAME)\
		$(LIBFT)/$(LIBFT_NAME).a\
		$(LIBFTFT_PRINTF)/$(LIBFTFT_PRINTF_NAME).a\
		$(LIBFT_LS)/$(LIBFT_LS_NAME).a

clean:
	@cd $(LIBFT) && make clean
	@cd $(LIBFTFT_PRINTF) && make clean
	@cd $(LIBFT_LS) && make clean
	@/bin/rm -f $(SRC:.c=.o)

fclean: clean
	@cd $(LIBFT) && make fclean
	@cd $(LIBFTFT_PRINTF) && make fclean
	@cd $(LIBFT_LS) && make fclean
	@/bin/rm -f $(NAME)

re: fclean all
	@cd $(LIBFT) && make re
	@cd $(LIBFTFT_PRINTF) && make re
	@cd $(LIBFT_LS) && make re
