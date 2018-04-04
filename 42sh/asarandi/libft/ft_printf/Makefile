# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 09:00:12 by asarandi          #+#    #+#              #
#    Updated: 2018/03/31 04:22:13 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -g -Wall -Werror -Wextra -I. -c
FILES	=	add_precision.c \
			add_width.c \
			format_ioux.c \
			format_csws.c \
			ft_printf.c \
			get_char.c \
			get_double.c \
			non_numeric.c \
			get_specs.c \
			init_lib.c \
			is_format.c \
			libft_functions.c \
			print_number.c \
			string_op.c \
			wchar_to_utf8.c \
			iso8601.c \
			colors.c \
			float_cosmetics.c
OBJ		= $(FILES:%.c=%.o)
INC		= libftprintf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(SONAME)

re: fclean all
