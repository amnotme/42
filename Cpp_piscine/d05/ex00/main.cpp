/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:13:16 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/03 00:13:17 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

int 			main( void ) {

	Bureaucrat one = Bureaucrat("Leo", 150);
	Bureaucrat two = Bureaucrat("Ivan", 1);

	std::cout << one.getName() << " " << one.getGrade() << std::endl;
	std::cout << two.getName() << " " << two.getGrade() << std::endl;

	one.incrementGrade();
	two.decrementGrade();

	std::cout << one.getName() << " " << one.getGrade() << std::endl;
	std::cout << two.getName() << " " << two.getGrade() << std::endl;
	try {

		// one.decrementGrade();
		// std::cout << one << std::endl;
    //
		// one.decrementGrade();
		// std::cout << one << std::endl;

		two.incrementGrade();
		std::cout << two << std::endl;

		two.incrementGrade();
		std::cout << two << std::endl;
	}
	catch ( std::exception & e ) {
		std::cout << e.what()  << std::endl;
	}
	return (0);
}
