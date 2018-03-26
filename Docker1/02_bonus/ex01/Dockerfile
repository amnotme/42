# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 14:45:38 by lhernand          #+#    #+#              #
#    Updated: 2018/03/26 15:04:06 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FROM debian:latest

RUN  apt-get update -y && \
	 apt-get upgrade -y && \
	 apt-get install vim -y && \
	 apt-get install gcc -y && \
	 apt-get install valgrind -y 

RUN echo "#include <stdlib.h>" >> test.c && \
	echo "" >> test.c && \
	echo "void f(void)" >> test.c && \
	echo "{" >> test.c && \
	echo "		int *x =malloc(10 * sizeof(int));" >> test.c && \
	echo "		x[10] = 0;" >> test.c && \
	echo "}" >> test.c && \
	echo "" >> test.c && \
	echo "int main(void)" >> test.c && \
	echo "{" >> test.c && \
	echo "		f();" >> test.c && \
	echo "		return (0);" >> test.c && \
	echo "}" >> test.c

RUN cat test.c

RUN ["gcc", "-Wall", "-Wextra", "-Werror", "-g", "-o", "test", "test.c"]
CMD ["valgrind", "--leak-check=yes", "./test"]
