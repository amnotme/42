# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 13:08:36 by lhernand          #+#    #+#              #
#    Updated: 2018/07/06 16:21:02 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CXXFILES = main.cpp \

all : $(NAME)

$(NAME) :
	@echo "\033[1;32mCompiling"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(CXXFILES)
	@echo "Done\033[0m"

fclean :
	@echo "\033[1;31mFull Clean"
	@/bin/rm -f $(NAME)
	@echo "Done\033[0m"

clean :
	@echo "\033[1;31mRegular Clean"
	@/bin/rm -f $(NAME)
	@echo "Done\033[0m"

re: fclean all

.PHONY: re, fclean, all
