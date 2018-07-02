/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:07 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 06:05:22 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H
# include <cstdint>
# include <iostream>

class	Game;
class	Projectile;

class	Entity
{

  public:

    Entity(void);
    Entity(Entity const &obj);
    ~Entity( void );
    Entity				&operator=( Entity const & rhs );

    //getters
    int         		getHp( void ) const;
    int         		getPosX( void ) const;
    int         		getPosY( void ) const;
    int         		getSpeed( void ) const;
    char const *const	*getSprite( void ) const;
	int					getSpriteLength(void) const;
	int					getSpriteWidth(void) const;

    //setters
    void        		setHp( int const hp );
    void        		setPosX( int posX );
    void        		setPosY( int posY );
    void        		setSpeed( int const speed );

    bool        		canMove( void ) const;
	int					getDir(void) const;
	void				setDir(int dir);
	int					advance(void);

	Projectile *const	*getBullets(void) const;
	int					getNumBullets(void) const;
	void				removeBullet(void);
    bool        		canShoot( void ) const;
	void				shoot(int dir);

  protected:

    int					_hp;
	int					_dir;
    int         		_posX;
    int         		_posY;
    int         		_speed;
    char const			*_sprite[5];
	int					_spriteLength;
	int					_spriteWidth;
	Projectile			*_bullets[25];
	int					_nbullets;
    uint64_t			_move;
    uint64_t    		_shoot;
};

#endif
