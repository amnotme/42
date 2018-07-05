/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 02:48:50 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/05 04:32:54 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void    iter(T  x[], size_t y, T const func( T const & x)) {
    srand(time(NULL));
    size_t i = 0;
    std::string arr[] = {"\033[1;32m", "\033[1;31m", "\033[1;33m", "\033[1;34m",
                        "\033[1;35m", "\033[1;36m", "\033[1;37m", "\033[1;38m"};

    while (y > i) {
        std::cout << arr[rand() % 8] << func(x[i++]) << " " ;
    }
    std::cout << "\033[0m" << std::endl;
}

template <typename T>
T const   foo( T const & x ) {
  return (x + x);
}

template <size_t SIZE, typename T >
inline size_t array_size(T  (&)[SIZE]) {
    	return SIZE;
}
