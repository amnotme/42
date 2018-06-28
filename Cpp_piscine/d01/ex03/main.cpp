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
#include "ZombieHorde.hpp"

int     main( void ) {

  ZombieHorde zoms = ZombieHorde(1000);
  zoms.announce();

  ZombieHorde zoms2 = ZombieHorde(1);
  zoms2.announce();
  return (0);
}
