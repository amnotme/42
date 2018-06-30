/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:56:56 by lhernand          #+#    #+#             */
/*   Updated: 2018/06/30 14:56:57 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_H
# define ScavTrap_H
#include <string>


class ScavTrap {

  public:
  //constructors
  ScavTrap( void );
  ScavTrap( std::string name );
  ScavTrap( ScavTrap const & copy );
  ~ScavTrap( void );
  ScavTrap & operator=( ScavTrap const & other );

  //getters (Accessor Functions)
  int         getHp( void ) const;
  int         getMaxHp( void ) const;
  int         getMp( void ) const;
  int         getMaxMp( void ) const;
  int         getLevel( void ) const;
  int         getAttackM( void ) const;
  int         getAttackR( void ) const;
  int         getDamageAr( void ) const;
  std::string getName( void ) const;

  //setters (Modifier functions)
  void        setHp( int const hp );
  void        setMaxHp( int const maxHp );
  void        setMp( int const mp );
  void        setMaxMp( int const maxMp );
  void        setLevel( int const level );
  void        setAttackM( int const attackM );
  void        setAttackR( int const attackR );
  void        setDamageAr( int const damageAr );
  void        setName( std::string name );
  void        printStats( void );

  //Member Functions
  void        rangedAttack( std::string const & target );
  void        meleeAttack( std::string const & target );
  void        takeDamage( unsigned int amount );
  void        beRepaired( unsigned int amount );
  void        challengeNewcomer( std::string const & challenge );
  private:
  //private class member attributes
  int         _hp;
  int         _maxHp;
  int         _mp;
  int         _maxMp;
  int         _level;
  int         _attackM;
  int         _attackR;
  int         _damageAr;
  std::string _name;

};

void        red( void );
void        green( void );
void        white( void );

#endif
