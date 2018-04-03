# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 09:23:03 by brabo-hi          #+#    #+#              #
#    Updated: 2018/03/24 18:28:56 by brabo-hi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftls.a
SRC=\
	ft_get.c\
	ft_helper.c\
	ft_liste.c\
	ft_ls.c\
	ft_print.c\
	ft_sort.c\
	ft_utils.c\
	main.c
FLAGS=-Wextra -Wall -Werror -g

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(FLAGS)
	@ar -rc $(NAME) $(SRC:.c=.o)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(SRC:.c=.o)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f .a

re: fclean all