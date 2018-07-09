/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 19:14:24 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/06 23:42:07 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <iterator>

int			main( void )
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << RED <<  mstack.top() << WHITE << std::endl;
	mstack.pop();
	std::cout << YELLOW <<  mstack.size() << WHITE << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	// this will print them in order
	mstack.printSet();
	// the following lines are not necessary if using printSet();
	// will be left there for demo purposes.
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}
