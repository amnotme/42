/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 20:07:24 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/27 20:07:25 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void ) { srand (time(NULL)); }
ZombieEvent::~ZombieEvent( void ) { return ; }

std::string   ZombieEvent::getZombieType( void ) { return (this->_type); }

void          ZombieEvent::setZombieType( std::string type ) { this->_type = type; }

Zombie        *ZombieEvent::newZombie( std:: string name ) {
  return ( new Zombie( name, this->getZombieType()));
}

Zombie        *ZombieEvent::randomChump( void ) {
  std::string arr[5] = {"Thor", "Zaz", "Tony", "Gaetan", "Meo"};
  int randName = rand() % 5;
  Zombie *zombie = new Zombie(arr[randName],(this->_type == "" ? "Pawn" : this->_type));

  zombie->announce();
  return (zombie);
}
