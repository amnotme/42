/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:55:02 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/27 20:06:57 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
	public:
		Zombie( void );
		Zombie( std::string name, std::string type);
		~Zombie( void );

		void announce( void );
		std::string getName( void );
		std::string getType( void );
		void setName( std::string name);
		void setType( std::string type);

	private:
		std::string _name;
		std::string _type;
};

#endif
