# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/25 09:33:34 by lhernand          #+#    #+#              #
#    Updated: 2017/10/21 04:11:43 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#EXEC = test
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS =ft_atoi.o ft_lstmap.o ft_putchar_fd.o ft_strdel.o ft_strnequ.o \
      ft_bzero.o ft_lstnew.o ft_putendl.o ft_strdup.o ft_strnew.o \
      ft_memalloc.o ft_putendl_fd.o ft_strequ.o ft_strnstr.o ft_isalnum.o \
      ft_memccpy.o ft_putnbr.o ft_striter.o ft_strrchr.o ft_isalpha.o \
      ft_memchr.o ft_putnbr_fd.o ft_striteri.o ft_strsplit.o ft_isascii.o \
      ft_memcmp.o ft_putstr.o ft_strjoin.o ft_strstr.o ft_isdigit.o \
      ft_memcpy.o ft_putstr_fd.o ft_strlcat.o ft_strsub.o ft_isprint.o \
      ft_memdel.o ft_strcat.o ft_strlen.o ft_strtrim.o ft_itoa.o ft_memmove.o \
      ft_strchr.o ft_strmap.o ft_lstadd.o ft_memset.o ft_strclr.o \
      ft_strmapi.o ft_tolower.o ft_lstdel.o ft_strcmp.o \
      ft_strncat.o ft_toupper.o ft_lstdelone.o  \
      ft_strncmp.o ft_lstiter.o ft_putchar.o ft_strcpy.o ft_strncpy.o \
      blue.o bcyan.o bgreen.o bblue.o bmagenta.o bred.o byellow.o c_reset.o \
      cyan.o ft_atoi_handle.o ft_even.o ft_odd.o ft_iswspace.o ft_numlength.o \
      ft_wc.o ft_wl.o green.o magenta.o red.o true_false.o yellow.o

CFILES = ft_atoi.c ft_lstmap.c ft_putchar_fd.c ft_strdel.c ft_strnequ.c \
      ft_bzero.c ft_lstnew.c ft_putendl.c ft_strdup.c ft_strnew.c \
      ft_memalloc.c ft_putendl_fd.c ft_strequ.c ft_strnstr.c ft_isalnum.c \
      ft_memccpy.c ft_putnbr.c ft_striter.c ft_strrchr.c ft_isalpha.c \
      ft_memchr.c ft_putnbr_fd.c ft_striteri.c ft_strsplit.c ft_isascii.c \
      ft_memcmp.c ft_putstr.c ft_strjoin.c ft_strstr.c ft_isdigit.c \
      ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strsub.c ft_isprint.c \
      ft_memdel.c ft_strcat.c ft_strlen.c ft_strtrim.c ft_itoa.c ft_memmove.c \
      ft_strchr.c ft_strmap.c ft_lstadd.c ft_memset.c ft_strclr.c \
      ft_strmapi.c ft_tolower.c ft_lstdel.c ft_strcmp.c \
      ft_strncat.c ft_toupper.c ft_lstdelone.c  \
      ft_strncmp.c ft_lstiter.c ft_putchar.c ft_strcpy.c ft_strncpy.c \
      blue.c bcyan.c bgreen.c bblue.c bmagenta.c bred.c byellow.c c_reset.c \
      cyan.c ft_atoi_handle.c ft_even.c ft_odd.c ft_iswspace.c ft_numlength.c \
      ft_wc.c ft_wl.c green.c magenta.c red.c true_false.c yellow.c

#exec: all
#	@$(CC) -I. -o $(EXEC) $(CFILES)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(CFILES)
	@$(CC) $(CFlAGS) -c $(CFILES)

clean:
	@/bin/rm -f $(OBJECTS)

fclean:
	@/bin/rm -f $(OBJECTS) $(NAME) 
	$(EXEC)

re: fclean all

