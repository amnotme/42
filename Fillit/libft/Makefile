# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmalpart <gmalpart@estudent.42.us.org      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/25 16:22:47 by gmalpart          #+#    #+#              #
#    Updated: 2017/11/30 18:08:37 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
FILES = ft_putchar.c ft_putstr.c ft_strlen.c ft_swap.c ft_strcmp.c ft_putnbr.c \
	ft_bzero.c ft_bzero.c ft_memalloc.c ft_memcpy.c ft_memdel.c \
	ft_memset.c ft_strcpy.c ft_strncpy.c ft_strnew.c ft_strdup.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putnbr_fd.c \
	ft_strequ.c ft_putendl_fd.c ft_strclr.c ft_strrevert.c ft_strtrim.c \
	ft_atoi.c ft_itoa.c ft_nbrlen.c ft_strnequ.c ft_strcat.c ft_tolower.c \
	ft_toupper.c ft_isprint.c ft_isdigit.c ft_isascii.c ft_isalpha.c \
	ft_isalnum.c ft_strdel.c ft_strsub.c ft_strncat.c ft_strchr.c \
	ft_strlcat.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_memccpy.c ft_memmove.c ft_strstr.c ft_strnstr.c ft_lstnew.c \
	ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_itoa_base.c \
	ft_striter.c ft_striteri.c ft_lstmap.c ft_strmap.c ft_strmapi.c \
	ft_strjoin.c ft_strsplit.c ft_wordlen.c ft_wordcount.c ft_iswspace.c \
	ft_min.c ft_max.c ft_sqrt.c ft_lstadd_back.c

OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(FILES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib libft.a

clean:
	@/bin/rm -f $(OBJECTS)

fclean:	clean
	@/bin/rm -f $(NAME)

re:		fclean all

.PHONY: all, clean, fclean, re
