/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 19:14:40 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/12 01:49:44 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# define RED 	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define WHITE	"\033[0m"
#include <iterator>
#include <iostream>
#include <list>
#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>( void ) { 
			return; 
		}

		MutantStack( MutantStack const & other ) {
			*this = other;
			return;
		}

		~MutantStack<T>( void ) {
			return;
		}

		MutantStack &operator=( MutantStack const & rhs ) {
			this->_s = rhs._s;
			return;
		}

		typedef std::list<int>::iterator iterator;
		T const top( void ) {
			return (_s.front());
		}

		T const size( void ) {
			return (_s.size());
		}

		void push(T const value) {
			_s.push_front(value);
		}

		void pop(void)	{
			_s.pop_front();
		}

		iterator begin( void ) {
			return (_s.begin());
		}

		iterator end( void ) {
			return (_s.end());
		}
		
		void printSet( void ) const {
			std::ostream_iterator<int> screen(std::cout, "\033[1;32m - \033[0m");
			std::ostream_iterator<int> screen3(std::cout, "");
			copy(this->_s.begin(), --this->_s.end(), screen);
			copy(this->_s.end(), ++this->_s.end(), screen3);
			std::cout << std::endl;
		}

	private:
		std::list<T>			_s;

};

#endif
