# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 12:27:39 by lhernand          #+#    #+#              #
#    Updated: 2018/06/29 12:48:48 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = fragtrap
CXXFILES = FragTrap.cpp \
		   main.cpp

all: $(NAME)

$(NAME) :
	@echo "\033[1;32mCompiling"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(CXXFILES)
	@echo "Done \033[0m"

clean:
	@echo "\033[1;31mCleaning"
	@/bin/rm -f $(NAME)
	@echo "Done \033[0m"

fclean:
	@echo "\033[1;31mCleaning"
	@/bin/rm -f $(NAME)
	@echo "Done\033[0m"

re: fclean all
	
.PHONY: re, clean, fclean, all

