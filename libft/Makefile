# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/25 09:33:34 by lhernand          #+#    #+#              #
#    Updated: 2017/09/25 17:30:20 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = test
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = *.o
CFILES = *.c
HEADERS = libft.h

exec: all
	@$(CC) -I. -o $(EXEC) $(CFILES)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(CFILES)
	@$(CC) $(CFlAGS) -c $(CFILES)

clean:
	@/bin/rm -f $(OBJECTS)

fclean:
	@/bin/rm -f $(OBJECTS) $(NAME) $(EXEC)

re: fclean all
