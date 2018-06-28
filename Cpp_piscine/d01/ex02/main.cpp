/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 20:07:40 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/27 20:07:41 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int     main( void ) {

  Zombie zombie1 = Zombie("Xavier", "God");
  Zombie zombie2 = Zombie("Kwame", "Demi-god");
  ZombieEvent zombieEvent1;
  ZombieEvent zombieEvent2;

  zombie1.announce();
  zombie2.announce();
  zombieEvent1.setZombieType("Titan");

  Zombie *zombie3 = zombieEvent1.newZombie("Andy");
  Zombie *zombie4 = zombieEvent1.randomChump();
  Zombie *zombie5 = zombieEvent2.randomChump();

  delete zombie3;
  delete zombie4;
  delete zombie5;
  return (0);
}
