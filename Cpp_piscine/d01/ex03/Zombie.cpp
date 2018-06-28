/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 20:07:11 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/27 20:07:13 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie( void ) { return ; }
Zombie::Zombie( std::string name, std::string type ) : _name(name), _type(type) { return ;}
Zombie::~Zombie( void ) {
  std::cout << "zombie " << this->_name << " has been destroyed" << std::endl;
}

std::string Zombie::getName( void ) { return (this->_name ); }
std::string Zombie::getType( void ) { return (this->_type ); }

void Zombie::setName ( std::string name ) { this->_name = name; }
void Zombie::setType ( std::string type ) { this->_type = type; }
void Zombie::announce( void ) {
  std::cout << "<" << this->getName() <<" (" << this->getType()
            << ")> Braiiiiiiinnnssss..." << std::endl;
}
