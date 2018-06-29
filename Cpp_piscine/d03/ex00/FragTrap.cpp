#include <string>
#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
  std::cout << "Default FragTrap constructor called" << std::endl;
  this->_hp = 100;
  this->_maxHp = 100;
  this->_mp = 100;
  this->_maxMp = 100;
  this->_level = 1;
  this->_attackM = 30;
  this->_attackR = 20;
  this->_damageAr = 5;
  this->_name = "Frag";
  return ;
}


FragTrap::FragTrap( std::string name ) : _name(name) {
  this->_hp = 100;
  this->_maxHp = 100;
  this->_mp = 100;
  this->_maxMp = 100;
  this->_level = 1;
  this->_attackM = 30;
  this->_attackR = 20;
  this->_damageAr = 5;
  std::cout << "FragTrap created" << std::endl;
  return ;
}

FragTrap::FragTrap( FragTrap const & copy ) {
  *(this) = copy;
  std::cout << "Copy Fragtrap created" << std::endl;
  return ;
}

FragTrap::~FragTrap( void ) {
  std::cout << "Destroying -> " << this->_name  << " FragTrap" << std::endl;
  return ;
}


// FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
//   std::cout << "Assignation operator called" << std::endl;
//   return (NULL) ;
// }

//getters
std::string   FragTrap::getName( void ) const  { return (this->_name ); }
int   FragTrap::getHp( void ) const { return (this->_hp); }
int   FragTrap::getMaxHp( void ) const  { return (this->_maxHp); }
int   FragTrap::getMp( void ) const  { return (this->_mp); }
int   FragTrap::getMaxMp( void ) const { return (this->_maxMp); }
int   FragTrap::getLevel( void ) const { return (this->_level); }
int   FragTrap::getAttackM( void ) const  { return (this->_attackM); }
int   FragTrap::getAttackR( void ) const { return (this->_attackR); }
int   FragTrap::getDamageAr( void ) const { return (this->_damageAr); }

//setters
void  FragTrap::setName( std::string name ) { (this->_name = name); }
void  FragTrap::setHp( int const hp ) { (this->_hp = hp); }
void  FragTrap::setMaxHp( int const maxHp ) { (this->_maxHp = maxHp); }
void  FragTrap::setMp( int const mp ) { (this->_mp = mp); }
void  FragTrap::setMaxMp( int const maxMp ) { (this->_maxMp = maxMp); }
void  FragTrap::setLevel( int const level ) { (this->_level = level); }
void  FragTrap::setAttackM( int const attackM ) { (this->_attackM = attackM); }
void  FragTrap::setAttackR( int const attackR ) { (this->_attackR = attackR); }
void  FragTrap::setDamageAr( int const damageAr ) { (this->_damageAr = damageAr); }
