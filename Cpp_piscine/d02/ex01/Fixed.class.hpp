#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <cstdint>
#include <iostream>
#include <string>
#include <cmath>

class Fixed {
  public:
    Fixed( void );
    Fixed( Fixed const & src );
    Fixed( const int integer );
    Fixed( const float floatValue );
    ~Fixed( void );

    Fixed &             operator=(Fixed const & rhs );
    int                 getRawBits( void ) const;
    void                setRawBits( int const raw );
    float               toFloat( void ) const ;
    int                 toInt( void ) const ;

  private:
    int                 _fixedNumber;
    static const int8_t _bits;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif
