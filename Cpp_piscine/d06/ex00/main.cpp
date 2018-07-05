/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:26:12 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/04 23:20:18 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <iomanip>
#include "Convert.hpp"

int				main(int argc, char **argv) {
	
	if (argc != 2)
		std::cout << "\033[1;32mInput one parameter\033[0m" << std::endl;
	else {	
		Convert converter;
		converter.parseInput(argv[1]);

	}
	return (0);
}
