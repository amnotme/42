/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 20:07:34 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/27 20:07:34 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

#include <string>
#include "Zombie.hpp"

class ZombieEvent {
  public:
    ZombieEvent( void );
    ~ZombieEvent( void );

    void          setZombieType( std::string type );
    std::string   getZombieType( void );
    Zombie       *newZombie( std::string name );
    Zombie       *randomChump( void );
  private:
    std::string   _type;
};

#endif
