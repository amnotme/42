/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 19:58:57 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/06 21:40:19 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>

Span::Span( unsigned int N ) : _N(N)
{
	return ;
}

Span::Span( Span const & other )
{
	*this = other;
	return ;
}

Span::~Span( void )
{
	return ;
}

size_t		Span::getSize( void ) const
{
	return(this->_vectList.size());
}

Span &Span::operator=( Span const & rhs )
{
	this->_vectList = rhs._vectList;
	this->_N		= rhs.getSize();
	return (*this);
}

/*
 ** longest span will use max and min_element stl functions to prove concept
 ** of understanding and usage of the <functional> library.
 ** both lines coudl be rewritten as :->
 ** size_t i = *(--_vectList.end());
 ** size_t j = *(_vectList.begin());
 ** return (i - j);
 */

size_t	Span::longestSpan( void ) 
{
	std::set<int>::iterator i = std::max_element(_vectList.begin(), _vectList.end());
	std::set<int>::iterator j = std::min_element(_vectList.begin(), _vectList.end());
	if (this->getSize() == 0 || this->getSize() == 1)
		throw ( std::string("There aren't enough elements to get a span" ) );
	else
		return (*i - *j);
}

size_t Span::shortestSpan( void ) 
{
	std::less<int> lessInt;
	std::set<int>::iterator j = _vectList.begin();
	std::set<int>::iterator k = (++_vectList.begin());
	size_t 					i = 0;
	int						l = *(--_vectList.end());
	if (this->getSize() == 0 || this->getSize() == 1)
		throw ( std::string("There aren't enough elements to get a span") );
	else
	{
		while (i < (this->getSize() - 1))
		{
			if (lessInt((*k - *j) , l))
				l = (*k - *j);
			++k;
			++j;
			i++;
		}
	}
	return (l);
}

bool	Span::isEmpty( void ) const 
{
	return(this->_vectList.empty());
}

void	Span::addNumber( int const number )
{
	if (this->getSize() < this->_N)
		this->_vectList.insert(number);
	else
		throw( std::string("No more elements can be added"));
}

void	Span::printSet( void ) const 
{
	std::ostream_iterator<int> screen(std::cout, "\033[1;32m - \033[0m");
	copy(this->_vectList.begin(), this->_vectList.end(), screen);
	std::cout << std::endl;
}

