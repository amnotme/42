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
#include <ctime>
#include "Phone.class.hpp"

void Phone::add(int *index)
{

  
    if (*index >= 8)
      std::cout << "No more space in your phonebook" << std::endl;
    else
    {
      std::cout << "\033[1;36mWhat's the first name?: ";
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
      std::cout << "What's the contact's birth date? : ";
      std::getline(std::cin, contact.bday);
      std::cout << "What's the contact's favorite meal? : ";
      std::getline(std::cin, contact.fmeal);
      std::cout << "What's the contact's underwear color? : ";
      std::getline(std::cin, contact.underwear_color);
      std::cout << "What's the contact's deepest darkest secret? : \033[0m";
      std::getline(std::cin, contact.dsecret);
      *index = (*index + 1);
    }
}

 void Phone::search(int index_to_search, int members_in_phonebook)
 {
   if (index_to_search > members_in_phonebook)
    {
     std::cout << "\033[1;31mThat contact entry is     blank\033[0m"
                << std::endl;
    }
   else
    {
     std::cout <<"\033[1;32mFirst Name: \033[1;36m"
               << contact.first_name << std::endl << "\033[0m";
     std::cout <<"\033[1;32mLast Name: \033[1;36m"
               << contact.last_name << std::endl << "\033[0m";
     std::cout <<"\033[1;32mNickame: \033[1;36m"
               << contact.nickname << std::endl << "\033[0m";
     std::cout <<"\033[1;32mPostal Address: \033[1;36m"
               << contact.address << std::endl << "\033[0m";
     std::cout <<"\033[1;32mEmail Address: \033[1;36m"
               << contact.email << std::endl << "\033[0m";
     std::cout <<"\033[1;32mPhone Number: \033[1;36m"
               << contact.pnumber << std::endl << "\033[0m";
     std::cout <<"\033[1;32mBirth Date: \033[1;36m"
               << contact.bday << std::endl << "\033[0m";
     std::cout <<"\033[1;32mFavorite Meal: \033[1;36m"
               << contact.fmeal << std::endl << "\033[0m";
     std::cout <<"\033[1;32mUnderwear Color: \033[1;36m"
               << contact.underwear_color << std::endl << "\033[0m";
     std::cout <<"\033[1;32mDeepest Secret: \033[1;36m"
               << contact.dsecret << std::endl << "\033[0m";
    }
 }
