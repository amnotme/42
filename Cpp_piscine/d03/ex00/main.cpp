#include <string>
#include <iostream>
#include <unistd.h>
//#include "FragTrap.hpp"
#include "FragTrap.hpp"



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

  FragTrap frag1; sleep(1);
  FragTrap frag2 = FragTrap("Leo"); sleep(1);

  red();    frag1.rangedAttack("Leo"); sleep(1);
  green();  frag2.takeDamage(15); sleep(1);
  green();  frag2.meleeAttack("Clap trap"); sleep(1);
  red();    frag1.takeDamage(20); sleep(1);
  red();    frag1.beRepaired(40); sleep(1);
  green();  frag2.vaulthunter_to__exe("ClapTrap"); sleep(1);
  red();    frag1.takeDamage(50); sleep(1);
  red();    frag1.vaulthunter_to__exe("Leo"); sleep(1);
  green();  frag2.takeDamage(100); sleep(1);
  white();

  

  return (0);
}
