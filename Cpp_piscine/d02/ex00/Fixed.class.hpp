#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <cstdint>

class Fixed {
  public:
    Fixed( void );
    Fixed( Fixed const & src );
    ~Fixed( void );

    Fixed &             operator=(Fixed const & rhs );
    int                 getRawBits( void ) const;
    void                setRawBits( int const raw );

  private:
    int                 _fixedNumber;
    static const int8_t _bits;

};

#endif
