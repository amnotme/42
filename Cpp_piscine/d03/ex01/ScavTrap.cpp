/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:56:43 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/30 14:56:44 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
  srand (time(NULL));
  std::cout << "ClapTrap -- start bootup sequence." << std::endl;
  this->_hp = 100;
  this->_maxHp = 100;
  this->_mp = 50;
  this->_maxMp = 50;
  this->_level = 1;
  this->_attackM = 20;
  this->_attackR = 15;
  this->_damageAr = 3;
  this->_name = "ScavTrap";
  return ;
}

ScavTrap::ScavTrap( std::string name ) : _name(name) {
  srand (time(NULL));
  std::cout << "ScavTrap -- start bootup sequence." << std::endl;
  this->_hp = 100;
  this->_maxHp = 100;
  this->_mp = 50;
  this->_maxMp = 50;
  this->_level = 1;
  this->_attackM = 20;
  this->_attackR = 15;
  this->_damageAr = 3;
  std::cout << name <<  " -- start bootup sequence." << std::endl;
  return ;
}

ScavTrap::ScavTrap( ScavTrap const & copy ) {
  *(this) = copy;
  std::cout << " Copying..." << std::endl;
  std::cout << " That guy looks an awful lot like a Badass !" << std::endl;
  return ;
}

ScavTrap::~ScavTrap( void ) {
  std::cout << "<" << this->_name  << "> Robot down!" << std::endl;
  sleep(1);
  return ;
}


ScavTrap & ScavTrap::operator=( ScavTrap const & other ) {

  std::cout << "Holy crap, that worked?" << std::endl;
  std::cout << "ScavTrap: " << other.getName()
            << " is being copied into ScavTrap: " << this->getName()
            << " !" << std::endl;
  if (this != &other) {
    this->_name = other.getName();
    this->_hp = other.getHp();
    this->_maxHp = other.getMaxHp();
    this->_mp = other.getMp();
    this->_maxMp = other.getMaxMp();
    this->_level = other.getLevel();
    this->_attackM = other.getAttackM();
    this->_attackR = other.getAttackR();
    this->_damageAr = other.getDamageAr();
  }
  return (*this);
}

//member functions
void    ScavTrap::rangedAttack( std::string const & target ) {
  int mpUsed = 0;

  mpUsed = ( this->_mp - 10 );
  this->setMp(mpUsed >= 0 ? mpUsed : 0);
  if (this->_mp > 0) {
    std::cout << "SCAV2G-TP <" << this->_name
              << "> attacks <" << target << "> at range, causing "
              << "<" << this->_attackR
              << "> points of damage !" << std::endl;
  } else {
    std::cout << "SCAV2G-TP <" << this->_name
              << "> Mp is < 0 >.  You cannot attack at this moment"
              << std::endl;
  }
  this->printStats();
}

void    ScavTrap::meleeAttack( std::string const & target ) {
  int mpUsed = 0;

  mpUsed = ( this->_mp - 10 );
  this->setMp(mpUsed >= 0 ? mpUsed : 0);
  if (this->_mp > 0) {
    std::cout << "SCAV2G-TP <" << this->_name
              << "> attacks <" << target << "> nervously close... "
              << "<" << this->_attackM
              << "> points of damage were inflicted !" << std::endl;
  } else {
    std::cout << "SCAV2G-TP <" << this->_name
              << "> Mp is < 0 >.  You cannot attack at this moment"
              << std::endl;
  }
  this->printStats();
}

void    ScavTrap::takeDamage( unsigned int amount ) {
  int damageTaken = 0;
  std::cout << "SCAV2G-TP <" << this->_name
            << "> has been damaged by <" << amount
            << "> points !" << std::endl;
  damageTaken = (this->_damageAr + this->_hp - amount);
  this->setHp(damageTaken >= 0 ? damageTaken : 0);
  this->printStats();
}

void    ScavTrap::beRepaired( unsigned int amount ) {
  int hpToRepair = 0;
  int mpToRepair = 0;
  hpToRepair = (this->_hp + amount);
  mpToRepair = (this->_mp + amount);
  this->setHp(hpToRepair <= this->_maxHp ? hpToRepair : this->_maxHp);
  this->setMp(mpToRepair <= this->_maxMp ? mpToRepair : this->_maxMp);

  std::cout << "SCAV2G-TP <" << this->_name
          << "> Has received a healing pack. Health and Energy increased by <"
          << amount << "> points !" << std::endl;
  this->printStats();
}

void     ScavTrap::printStats( void ) {
  std::cout << "<" << this->_name << "> : " << std::endl;
  std::cout << "  Health        : " << this->getHp() << std::endl;
  std::cout << "  Energy Points : " << this->getMp() << std::endl;
  std::cout << "  Level         : " << this->getLevel() << std::endl;
  std::cout << "  Armor         : " << this->getDamageAr() << std::endl;
}

void     ScavTrap::challengeNewcomer( std::string const & challenge ) {
  int mpUsed = 0;
  int randAttack = rand() % 5;

  static const std::string arr[5] = {"Dance for me monkey, DANCE!!!! ",
                        "Go To a dark circular room. Find the corner and sit there... ",
                        "Make your nose and elbow touch... without disassmebling any parts of yourself",
                        "Take a cold shower with your circuit board's door ajar",
                        "Turn off your own power supply and turn in it back on afterwards... Bwahahahah!"};

  mpUsed = ( this->_mp - 25 );
  this->setMp(mpUsed >= 0 ? mpUsed : 0);
  if (this->_mp > 0) {
    std::cout << "SCAV2G-TP <" << this->_name
              << "> challenges <" << challenge << "> to "
              << arr[randAttack] << " !" << std::endl;
  } else {
    std::cout << "SCAV2G-TP <" << this->_name
              << "> Mp is < 0 >.  You cannot attack at this moment"
              << std::endl;
  }
  this->printStats();
}

//getters
std::string   ScavTrap::getName( void ) const  { return (this->_name ); }
int   ScavTrap::getHp( void ) const { return (this->_hp); }
int   ScavTrap::getMaxHp( void ) const  { return (this->_maxHp); }
int   ScavTrap::getMp( void ) const  { return (this->_mp); }
int   ScavTrap::getMaxMp( void ) const { return (this->_maxMp); }
int   ScavTrap::getLevel( void ) const { return (this->_level); }
int   ScavTrap::getAttackM( void ) const  { return (this->_attackM); }
int   ScavTrap::getAttackR( void ) const { return (this->_attackR); }
int   ScavTrap::getDamageAr( void ) const { return (this->_damageAr); }

//setters
void  ScavTrap::setName( std::string name ) { (this->_name = name); }
void  ScavTrap::setHp( int const hp ) { (this->_hp = hp); }
void  ScavTrap::setMaxHp( int const maxHp ) { (this->_maxHp = maxHp); }
void  ScavTrap::setMp( int const mp ) { (this->_mp = mp); }
void  ScavTrap::setMaxMp( int const maxMp ) { (this->_maxMp = maxMp); }
void  ScavTrap::setLevel( int const level ) { (this->_level = level); }
void  ScavTrap::setAttackM( int const attackM ) { (this->_attackM = attackM); }
void  ScavTrap::setAttackR( int const attackR ) { (this->_attackR = attackR); }
void  ScavTrap::setDamageAr( int const damageAr ) { (this->_damageAr = damageAr); }
