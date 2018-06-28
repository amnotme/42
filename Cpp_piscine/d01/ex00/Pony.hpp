#ifndef PONY_H
# define PONY_H

#include <string>
#include <iostream>

class Pony {
  private:
    std::string _name;

  public:

    Pony( std::string name );
    ~Pony( void );

};
void ponyOnTheHeap( void );
void ponyOnTheStack( void );

#endif
