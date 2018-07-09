/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 19:58:42 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/06 21:44:51 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 		<iostream>
#include 		<string>
#include 		"span.hpp"
#define RED 	"\033[1;32m"
#define GREEN 	"\033[1;31m"
#define YELLOW	"\033[1;33m"
#define WHITE	"\033[0m"

int main(void)
{
	Span sp = Span(5);
	Span sp2 = Span(5);

	std::cout << YELLOW << "sp empty? -> " <<  std::boolalpha 
		<< sp.isEmpty() << WHITE <<  std::endl;
	try 
	{
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << YELLOW << "sp empty? -> " << std::boolalpha 
			<< sp.isEmpty() << WHITE << std::endl;
		sp.printSet();

		sp2 = sp;
		sp2.printSet();
	}
	catch ( std::string str)
	{
		std::cout << str << std::endl;
	}
	try 
	{
		std::cout << GREEN << "Shortest Span -> " 
			<< sp.shortestSpan() << WHITE <<  std::endl;
		std::cout << GREEN << "Longest Span -> "
			<< sp.longestSpan() << WHITE  << std::endl;
	}
	catch ( std::string str2)
	{
		std::cout << str2 << std::endl;
	}
	return (0);
}
