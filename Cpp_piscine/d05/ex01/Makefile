# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 12:37:48 by lhernand          #+#    #+#              #
#    Updated: 2018/07/03 20:31:57 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic 
CXXFILES = Bureaucrat.cpp \
		   Form.cpp \
		   main.cpp

all: $(NAME)

$(NAME):
	@echo "\033[1;32mCompiling"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(CXXFILES)
	@echo "Done\033[0m"

fclean:
	@echo "\033[1;31mFull Clean"
	@/bin/rm -f $(NAME)
	@echo "Done\033[0m"

clean:
	@echo "\033[1;31mClean"
	@/bin/rm -f $(NAME)
	@echo "Done\033[0m"

re: fclean all

.PHONY: re, fclean, all
