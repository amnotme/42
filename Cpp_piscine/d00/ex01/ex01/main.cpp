/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:56:44 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/26 01:21:43 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <locale>
#include <sstream>
#include "Phone.class.hpp"

#define MAX_CONTACTS 8

void					show_options(void)
{
	std::cout << "\033[1:37mPlease make a selection from the following menu" << std::endl;
	std::cout << "(Add) -> this will create a new contact" << std::endl;
	std::cout << "(Search) -> this will search for a contact" << std::endl;
	std::cout << "(Exit) -> this will terminate the program\033[0m" << std::endl;
}

std::string		truncate(std::string str)
{
	if (str.length() > 10)
		str = (str.substr(0, 9) + ".");
	else
		str = (str.substr(0, 10));
	return (str);
}

int						take_input(void)
{
	int					count;
	char 				c;
	std::string response;
	std::locale loc;

	c = '\0';
	count = 0;
	std::getline(std::cin,response);
	while (response[count])
	{
		c = std::tolower(response[count], loc);
		response[count++] = c;
	}
	if (response.compare("add") == 0)
		return (1);
	else if (response.compare("search") == 0)
		return (2);
	else if (response.compare("exit") == 0)
		return (3);
	else
		std::cout << "\033[1;31mInvalid entry, Please try again\033[0m" << std::endl;
	return (0);

}

int						main(void)
{
	int 							option;
	int 							idx;
	int 							search_idx;
	int								response_int;
	std::string 			response;
	Phone 						phonebook[MAX_CONTACTS];


	idx = 0;
	option = 0;
	while (option != 3)
	{
		show_options();
		option = take_input();
		if (option == 1)
			phonebook[idx].add(&idx);
		else if (option == 2)
		{
			if (idx == 0)
			{
				std::cout << "\033[1;31mNo search to be made. Phonebook is empty\033[0m"
					<< std::endl;
			}
			else
			{
				search_idx = 0;
				while (search_idx < idx)
				{
					std::cout << "\033[1;36m|" << std::right << std::setw(9) << (search_idx + 1) << "|"
					<< std::right << std::setw(11 - (truncate(phonebook[search_idx].contact.first_name)).length())
					<< truncate(phonebook[search_idx].contact.first_name) << "|"
					<< std::right << std::setw(11 - (truncate(phonebook[search_idx].contact.last_name)).length())
					<< truncate(phonebook[search_idx].contact.last_name) << "|"
					<< std::right << std::setw(11 - (truncate(phonebook[search_idx].contact.nickname)).length())
					<< truncate(phonebook[search_idx].contact.nickname) << "|"
					<< std::endl << "\033[0m";
					search_idx++;
				}
				std::cout << "\033[1;36mChoose the number of contact to display"
					<< std::endl << "Or enter (9) to return to the menu: \033[0m";
				std::getline(std::cin, response);
				std::stringstream s(response);
				s >> response_int;
				if (!(response_int <= 9 && response_int >= 1))
					std::cout << "\033[1;31mInvalid entry, Please try again\033[0m"
						<< std::endl;
				else if (response_int == 9)
					continue ;
				else
					phonebook[response_int - 1].search(response_int, idx);
			}
		}
	}
	std::cout << "\033[1;32mThe program has termniated" << std::endl
		<< "Good Bye!\033[0m" << std::endl;
	return (0);
}
