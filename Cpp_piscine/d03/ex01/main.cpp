/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:57:09 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/30 14:57:10 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <unistd.h>
#include "ScavTrap.hpp"


void     red( void ) {
  std::cout << "\033[1;31m";
}

void     green( void ) {
  std::cout << "\033[1;32m";
}

void     white( void ) {
  std::cout << "\033[0m";
}

int     main( void ) {

  ScavTrap scav1; sleep(1);
  ScavTrap scav2 = ScavTrap("Leo-2.0"); sleep(1);

  red();    scav1.rangedAttack("Leo-2.0"); sleep(1);
  green();  scav2.takeDamage(15); sleep(1);
  green();  scav2.meleeAttack("Scav trap"); sleep(1);
  red();    scav1.takeDamage(20); sleep(1);
  red();    scav1.beRepaired(40); sleep(1);
  green();  scav2.challengeNewcomer("Scav Trap"); sleep(1);
  red();    scav1.takeDamage(50); sleep(1);
  red();    scav1.challengeNewcomer("Leo-2.0"); sleep(1);
  green();  scav2.takeDamage(100); sleep(1);
  white();

  return (0);
}
