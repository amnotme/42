/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:35:07 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/25 21:20:56 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phone.class.hpp"

void Phone::add(int *index)
{
    if (*index >= 8)
      std::cout << "No more space in your phonebook" << std::endl;
    else
    {
      std::cout << "What's the first name?: ";
      std::getline(std::cin, contact.first_name);
      std::cout << "What's the last name? : ";
      std::getline(std::cin, contact.last_name);
      std::cout << "What's the nickname? : ";
      std::getline(std::cin, contact.nickname);
      std::cout << "What's the address? : ";
      std::getline(std::cin, contact.address);
      std::cout << "What's the email address? : ";
      std::getline(std::cin, contact.email);
      std::cout << "What's the phone number? : ";
      std::getline(std::cin, contact.pnumber);
      std::cout << "What's the contact's birthday? : ";
      std::getline(std::cin, contact.bday);
      std::cout << "What's the contact's favorite meal? : ";
      std::getline(std::cin, contact.fmeal);
      std::cout << "What's the contact's underwear color? : ";
      std::getline(std::cin, contact.underwear_color);
      std::cout << "What's the contact's deepest darkest secret? : ";
      std::getline(std::cin, contact.dsecret);
      *index = (*index + 1);
    }
}

// void Phone::search(int length)
// {
//
// }
