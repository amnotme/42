/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 02:48:41 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/05 04:27:47 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.cpp"
#include <iostream>
#include <string>

int			main( void ) {
	int a[] = {1, 2, 3, 4, 5};
	float b[] = {1.5f, 2.5f, 3.5f, 4.5f, 5.5f};
	double c[] = {2.0, 4.0, 6.0, 8.0, 10.0};
	char d[] = {33, 34, 35, 36, 37};
	std::string e[] = {"hello", "it's", "freaking", "late", "now"};

	iter(a, array_size(a), foo<int>);
	iter(b, array_size(b), foo<float>);
	iter(c, array_size(c), foo<double>);
	iter(d, array_size(d), foo<char>);
	iter(e, array_size(e), foo<std::string>);
	

	return (0);
}
