/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:30:53 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/27 19:34:29 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void		memoryLeak()
{
	std::string* panthere = new std::string("String panthere");
	std::cout << *panthere  << std::endl;
	delete panthere;
}
