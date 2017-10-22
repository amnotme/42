# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/25 09:33:34 by lhernand          #+#    #+#              #
#    Updated: 2017/10/21 20:38:15 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#EXEC = test  #commented out for main.c.. main.c must be added to compile
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = bblue.c \
		 bcyan.c \
		 bgreen.c \
		 blue.c \
		 bmagenta.c \
		 bred.c \
		 byellow.c \
		 c_reset.c \
		 cyan.c \
		 ft_atoi.c \
		 ft_atoi_handle.c \
		 ft_bzero.c \
		 ft_even.c \
		 ft_isalnum.c \
		 ft_isalpha.c \
		 ft_isascii.c \
		 ft_isdigit.c \
		 ft_isprime.c \
		 ft_isprint.c \
		 ft_iswspace.c \
		 ft_itoa.c \
		 ft_lstadd.c \
		 ft_lstdel.c \
		 ft_lstdelone.c \
		 ft_lstiter.c \
		 ft_lstmap.c \
		 ft_lstnew.c \
		 ft_memalloc.c \
		 ft_memccpy.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_memcpy.c \
		 ft_memdel.c \
		 ft_memmove.c \
		 ft_memset.c \
		 ft_numlength.c \
		 ft_odd.c \
		 ft_putchar.c \
		 ft_putchar_fd.c \
		 ft_putendl.c \
		 ft_putendl_fd.c \
		 ft_putnbr.c \
		 ft_putnbr_fd.c \
		 ft_putstr.c \
		 ft_putstr_fd.c \
		 ft_strcat.c \
		 ft_strchr.c \
		 ft_strclr.c \
		 ft_strcmp.c \
		 ft_strcpy.c \
		 ft_strdel.c \
		 ft_strdup.c \
		 ft_strequ.c \
		 ft_striter.c \
		 ft_striteri.c \
		 ft_strjoin.c \
		 ft_strlcat.c \
		 ft_strlen.c \
		 ft_strmap.c \
		 ft_strmapi.c \
		 ft_strncat.c \
		 ft_strncmp.c \
		 ft_strncpy.c \
		 ft_strnequ.c \
		 ft_strnew.c \
		 ft_strnstr.c \
		 ft_strrchr.c \
		 ft_strsplit.c \
		 ft_strstr.c \
		 ft_strsub.c \
		 ft_strtrim.c \
		 ft_tolower.c \
		 ft_toupper.c \
		 ft_wc.c \
		 ft_wl.c \
		 green.c \
		 magenta.c \
		 red.c \
		 true_false.c \
		 yellow.c

#exec: all
#	@$(CC) -I. -o $(EXEC) $(CFILES)

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(CFILES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)	

clean:
	@/bin/rm -f $(OBJECTS)

fclean:
	@/bin/rm -f $(OBJECTS) $(NAME) 
#	$(EXEC)

re: fclean all

.PHONY: all, clean, fclean, re
