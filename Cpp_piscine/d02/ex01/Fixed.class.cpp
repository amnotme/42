#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.class.hpp"

const int8_t Fixed::_bits = 8 ;

Fixed::Fixed( void ) {
  std::cout << "Default constructor called" << std::endl;
  this->_fixedNumber = 0;
}

Fixed::Fixed( Fixed const & src ) {
  std::cout << "Copy constructor called" << std::endl;
  *(this) = src;
}

Fixed::Fixed( const int integer ) {
  std::cout << "Int constructor called" << std::endl;
  this->_fixedNumber = ( integer << this->_bits );
}

Fixed::Fixed( const float floatNumber ) {
  std::cout << "Float constructor called" << std::endl;
  this->_fixedNumber = roundf( floatNumber * ( 1 << this->_bits ));
}

Fixed::~Fixed( void ) {
  std::cout << "Default destructor called" << std::endl;
}

Fixed &  Fixed::operator=( Fixed const & rhs ) {
  std::cout << "Assignation operator called" << std::endl;
  this->_fixedNumber = rhs.getRawBits();
  return ( *this );
}

int      Fixed::getRawBits( void ) const {
  return ( this->_fixedNumber );
}

void     Fixed::setRawBits( int const raw ) {
  this->_fixedNumber = raw;
}

float    Fixed::toFloat( void ) const {
  return (float)(this->_fixedNumber) / (1 << this->_bits);
}

int      Fixed::toInt( void ) const {
  return (int)( this->_fixedNumber >> this->_bits );
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {
  o << (float)rhs.toFloat();
  return (o);
}
