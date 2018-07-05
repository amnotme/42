/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 02:22:42 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/05 02:35:21 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T & x, T  & y) {
	T temp;
	temp = x;
	x = y;
	y = temp;	
}

template <typename T>
T const & min(T const & x, T const & y) {
	return ( x >= y ? y : x);
}

template <typename T>
T const & max(T const & x, T const & y) {
	return ( x >= y ? x : y);
}
