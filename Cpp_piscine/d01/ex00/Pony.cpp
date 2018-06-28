#include <iostream>
#include <string>
#include "Pony.hpp"


Pony::Pony( std::string name ) : _name(name) {
  std::cout << "A pony " << this->_name << " has been being created." << std::endl;
}

Pony::~Pony( void ) {
  std::cout << "this pony is being destructed" << std::endl;
}

void ponyOnTheStack( void )  {
  Pony pony1 = Pony("Leo on the stack");
  Pony pony2 = Pony("Leo2 on the stack");
}

void ponyOnTheHeap( void ) {
  Pony* pony3 = new Pony("Leo3 on the Heap");
  Pony* pony4 = new Pony("Leo4 on the Heap");

  delete pony3;
  delete pony4;
}
