#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int number ) : _n(number) {
  srand (time(NULL));
  this->_zombies = new Zombie[this->_n];

  for (int i = 0 ; i < number ; i++ ) {
    (this->_zombies)[i].setName(this->randomChump());
    (this->_zombies)[i].setType("Pawn");
  }
}
ZombieHorde::ZombieHorde( void ) { srand (time(NULL)); }
ZombieHorde::~ZombieHorde( void ) { return ; }

std::string    ZombieHorde::randomChump( void ) {
  std::string arr[5] = {"Thor", "Zaz", "Tony", "Gaetan", "Meo"};
  std::string zombieName = "";
  int randName = rand() % 5;

  zombieName = (arr[randName]);
  return (zombieName);
}

void ZombieHorde::announce( void ) {
  for (int i = 0 ; i < this->_n ; i++) {
    (this->_zombies)[i].announce();
  }
}
