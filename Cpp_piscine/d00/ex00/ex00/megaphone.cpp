/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:47:48 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/25 14:47:52 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>

int		main(int argc, char **argv)
{
	int count;
	int len;
	int innerCount;
	std::locale loc;


	len = 0;
	count = 1;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (count < argc)
		{
			len = std::strlen(argv[count]);
			innerCount = 0;
			while (innerCount < len )
			{
				std::cout << std::toupper(argv[count][innerCount], loc);
				innerCount++;
			}
			count++;
		}
	std::cout << std::endl;
	}
	return (0);
}
