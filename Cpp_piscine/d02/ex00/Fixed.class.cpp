#include <iostream>
#include <string>
#include "Fixed.class.hpp"

Fixed::Fixed( void ) {
  std::cout << "Default constructor called" << std::endl;
  this->_fixedNumber = 0;
}

Fixed::Fixed( Fixed const & src ) {
  std::cout << "Copy constructor called" << std::endl;
  *(this) = src;
}

Fixed::~Fixed( void ) {
  std::cout << "Default destructor called" << std::endl;
}

Fixed &  Fixed::operator=( Fixed const & rhs ) {
  std::cout << "Assignment operator called" << std::endl;
  this->_fixedNumber = rhs.getRawBits();
  return ( *this );
}

int      Fixed::getRawBits( void ) const {
  std::cout << "getRawBits function is called" << std::endl;
  return ( this->_fixedNumber );
}

void     Fixed::setRawBits( int const raw ) {
  this->_fixedNumber = raw;
}

const int8_t Fixed::_bits = 8 ;
