/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:20:46 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/25 22:34:17 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_CLASS_H
# define PHONE_CLASS_H

#include <string>

struct Contact
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string address;
	std::string email;
	std::string pnumber;
	std::string bday;
	std::string fmeal;
	std::string underwear_color;
	std::string dsecret;
};


class Phone {
	public:
	Contact contact;
	void add(int *index);
	void search(int index_to_search, int members_in_phonebook);
	void exit();
};

#endif
