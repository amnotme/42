# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 20:42:56 by lhernand          #+#    #+#              #
#    Updated: 2018/07/04 23:20:09 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = converter
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CXXFILES = main.cpp \
		   Convert.cpp

all: $(NAME)

$(NAME):
	@echo "\033[1;32mCompiling"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(CXXFILES)
	@echo "Done\033[0m"

fclean :
	@echo "\033[1;31mFull clean"
	@/bin/rm -f $(NAME)
	@echo "Done\033[0m"

clean :
	@echo "\033[1;31mClean"
	@/bin/rm -f $(NAME)
	@echo "Done\033[0m"

re: fclean all

.PHONY: all, fclean, clean
