/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 13:02:05 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/06 16:26:50 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H
# include <vector>
# include <string>
# include <iostream>

template <size_t SIZE, typename T>
inline size_t array_size(T (&)[SIZE]) 
{
	return (SIZE);
}

template <typename T>
void		easyfind(T intList, int const & y) 
{
	int  i = 0;
	typename T::iterator it;

	for( it = intList.begin() ; it != intList.end() ; ++it) 
	{
		if (*it == y) 
		{
			std::cout << "\033[1;32mElement found at index ["
			   		  << i << "] element -> " 
					  << *it << "\033[0m" << std::endl;
			return ;
		}
		i++;
	}
	throw(std::string("\033[1;31mValue isn't in the list\033[0m"));	
}

#endif 
