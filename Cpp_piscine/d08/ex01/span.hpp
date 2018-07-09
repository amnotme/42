/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 19:59:09 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/06 16:45:32 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H
# include <set>

class Span {

	public:
		Span( unsigned int N );
		Span( Span const & other );
		~Span( void );
		Span &operator=( Span const & rhs);

		size_t		shortestSpan( void );
		size_t 		longestSpan( void );
		size_t		getSize( void ) const;
		void		addNumber( int const number );
		void		printSet( void ) const;
		bool		isEmpty( void ) const;
	private:
		std::set<int>		_vectList;
		size_t				_N;
};

#endif
