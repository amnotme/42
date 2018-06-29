#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <string>


class FragTrap {

  public:
  //constructors
  FragTrap( void );
  FragTrap( std::string name );
  FragTrap( FragTrap const & copy );
  ~FragTrap( void );
  // FragTrap & operator=( FragTrap const & rhs );

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


#endif
