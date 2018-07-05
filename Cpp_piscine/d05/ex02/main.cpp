/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:13:16 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/03 20:30:15 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int 			main( void ) {

	Bureaucrat one = Bureaucrat("Leo", 90);
	Bureaucrat two = Bureaucrat("Terrance", 120);
	Form form1 = Form("Form A", false, 100, 90);

	try {

		form1.beSigned(one);
		std::cout << form1 << std::endl;

		// form1.beSigned(two);
		// std::cout << form1 << std::endl;
    //
		one.signForm(form1);
		std::cout << one << std::endl;

		// two.signForm(form1);
		// std::cout << two << std::endl;

	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "your code is really messed up" << std::endl;
	}
	return (0);
}
