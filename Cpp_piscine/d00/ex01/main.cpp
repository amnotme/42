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
#include <string>
#include <locale>
#include "Phone.class.hpp"

#define MAX_CONTACTS 7

void 	show_options(void)
{
	std::cout << "Please make a selection from the following menu" << std::endl;
	std::cout << "(Add) -> this will create a new contact" << std::endl;
	std::cout << "(Search) -> this will search for a contact" << std::endl;
	std::cout << "(Exit) -> this will terminate the program" << std::endl;
}

int		take_input(void)
{
	int			count;
	char 		c;
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
		std::cout << "Invalid entry, Please try again" << std::endl;
	return (0);
	
}
int		main(void) 
{
	int option;
	int idx;
	int search_idx;

	idx = 0;
	Phone phonebook[MAX_CONTACTS];
	
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
				std::cout << "No search to be made. Phonebook is empty" 
					<< std::endl;
			}
			else 
			{
				search_idx = 0;
				while (search_idx < idx)
				{
					std::cout << "|" << search_idx << "|" 
						<< phonebook[search_idx].contact.first_name << "|"
						<< phonebook[search_idx].contact.last_name << "|"
						<< phonebook[search_idx].contact.nickname << "|"
						<< std::endl;
					search_idx++;
				}
			}
		}
	}
	std::cout << "The program has termniated" << std::endl
		<< "Good Bye!" << std::endl;
	return (0);
}
