/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:56:09 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/30 14:56:13 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
  srand (time(NULL));
  std::cout << "ClapTrap -- start bootup sequence." << std::endl;
  this->_hp = 100;
  this->_maxHp = 100;
  this->_mp = 100;
  this->_maxMp = 100;
  this->_level = 1;
  this->_attackM = 30;
  this->_attackR = 20;
  this->_damageAr = 5;
  this->_name = "ClapTrap";
  return ;
}

FragTrap::FragTrap( std::string name ) : _name(name) {
  srand (time(NULL));
  this->_hp = 100;
  this->_maxHp = 100;
  this->_mp = 100;
  this->_maxMp = 100;
  this->_level = 1;
  this->_attackM = 30;
  this->_attackR = 20;
  this->_damageAr = 5;
  std::cout << name <<  " -- start bootup sequence." << std::endl;
  return ;
}

FragTrap::FragTrap( FragTrap const & copy ) {
  *(this) = copy;
  std::cout << " Copying..." << std::endl;
  std::cout << " Yeahyeahyeah, just -- wait, you can actually do that?" << std::endl;
  return ;
}

FragTrap::~FragTrap( void ) {
  std::cout << "<" << this->_name  << "> Dang it. I'm out !" << std::endl;
  sleep(1);
  return ;
}


FragTrap & FragTrap::operator=( FragTrap const & other ) {

  std::cout << "What? No, nooo, you are so STUPID! Whatever. You're welcome." << std::endl;
  std::cout << "FragTrap: " << other.getName()
            << " is being copied into FragTrap: " << this->getName()
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
void    FragTrap::rangedAttack( std::string const & target ) {
  int mpUsed = 0;

  mpUsed = ( this->_mp - 10 );
  this->setMp(mpUsed >= 0 ? mpUsed : 0);
  if (this->_mp > 0) {
    std::cout << "FR4G-TP <" << this->_name
              << "> attacks <" << target << "> at range, causing "
              << "<" << this->_attackR
              << "> points of damage !" << std::endl;
  } else {
    std::cout << "FR4G-TP <" << this->_name
              << "> Mp is < 0 >.  You cannot attack at this moment"
              << std::endl;
  }
  this->printStats();
}

void    FragTrap::meleeAttack( std::string const & target ) {
  int mpUsed = 0;

  mpUsed = ( this->_mp - 10 );
  this->setMp(mpUsed >= 0 ? mpUsed : 0);
  if (this->_mp > 0) {
    std::cout << "FR4G-TP <" << this->_name
              << "> attacks <" << target << "> at close range, causing "
              << "<" << this->_attackM
              << "> points of damage !" << std::endl;
  } else {
    std::cout << "FR4G-TP <" << this->_name
              << "> Mp is < 0 >.  You cannot attack at this moment"
              << std::endl;
  }
  this->printStats();
}

void    FragTrap::takeDamage( unsigned int amount ) {
  int damageTaken = 0;
  std::cout << "FR4G-TP <" << this->_name
            << "> has taken <" << amount
            << "> points of damage !" << std::endl;
  damageTaken = (this->_damageAr + this->_hp - amount);
  this->setHp(damageTaken >= 0 ? damageTaken : 0);
  this->printStats();
}

void    FragTrap::beRepaired( unsigned int amount ) {
  int hpToRepair = 0;
  int mpToRepair = 0;
  hpToRepair = (this->_hp + amount);
  mpToRepair = (this->_mp + amount);
  this->setHp(hpToRepair <= this->_maxHp ? hpToRepair : this->_maxHp);
  this->setMp(mpToRepair <= this->_maxMp ? mpToRepair : this->_maxMp);

  std::cout << "FR4G-TP <" << this->_name
          << "> is being repaired.  Health and Energy increased by <"
          << amount << "> points !" << std::endl;
  this->printStats();
}

void     FragTrap::printStats( void ) {
  std::cout << "<" << this->_name << "> : " << std::endl;
  std::cout << "  Health        : " << this->getHp() << std::endl;
  std::cout << "  Energy Points : " << this->getMp() << std::endl;
  std::cout << "  Level         : " << this->getLevel() << std::endl;
  std::cout << "  Armor         : " << this->getDamageAr() << std::endl;
}

void     FragTrap::vaulthunter_to__exe( std::string const & target ) {
  int mpUsed = 0;
  int randAttack = rand() % 5;

  std::string arr[5] = {"Attempting to poke eyes out ",
                        "Shooting groin with vivi-gun ",
                        "Making an appropriate advance... makes ears bleed",
                        "Head-butting... with butt... butt-butt",
                        "Telling a really REALLY bad joke"};

  mpUsed = ( this->_mp - 25 );
  this->setMp(mpUsed >= 0 ? mpUsed : 0);
  if (this->_mp > 0) {
    std::cout << "FR4G-TP <" << this->_name
              << "> attacks <" << target << ">  by "
              << arr[randAttack] << " !" << std::endl;
  } else {
    std::cout << "FR4G-TP <" << this->_name
              << "> Mp is < 0 >.  You cannot attack at this moment"
              << std::endl;
  }
  this->printStats();
}

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
