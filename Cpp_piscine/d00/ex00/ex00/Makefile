# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 14:47:36 by lhernand          #+#    #+#              #
#    Updated: 2018/06/26 13:13:20 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = clang++
CFLAGS = -Wall -Wextra -Werror
CFILES = megaphone.cpp

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o  $(NAME) $(CFILES)

clean:
	/bin/rm -f $(NAME)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: re, clean, fclean, all
