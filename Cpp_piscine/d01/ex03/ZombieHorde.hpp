#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

class ZombieHorde {

  public:
    ZombieHorde( int number );
    ZombieHorde( void );
    ~ZombieHorde( void );
    void        announce(void) const;
    std::string randomChump(void);

  private:
    Zombie      *_zombies;
    int         _n;

};

#endif
