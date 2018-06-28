/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:36:33 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/27 19:46:21 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


int			main(void)
{
	
	std::string  str = "HI THIS IS BRAIN";
	std::string* strPtr = &str;
	std::string& strRef = str;

	std::cout << "1. this is the string -> " << str 
			  << "\n2. this is the pointer -> " << *strPtr 
			  << "\n3. this is the reference -> " << strRef << std::endl;
	return (0);
}
