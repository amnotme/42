# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passef <passef@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/23 22:56:11 by brabo-hi          #+#    #+#              #
#    Updated: 2018/03/26 16:31:17 by passef           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
SRC =	ft_add.c \
		ft_convert.c \
		ft_find.c \
		ft_get.c \
		ft_help.c \
		ft_helper.c \
		ft_printf.c \
		ft_set1.c \
		ft_set2.c

FLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(FLAGS)
	@ar -rc $(NAME) $(SRC:.c=.o)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(SRC:.c=.o)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
