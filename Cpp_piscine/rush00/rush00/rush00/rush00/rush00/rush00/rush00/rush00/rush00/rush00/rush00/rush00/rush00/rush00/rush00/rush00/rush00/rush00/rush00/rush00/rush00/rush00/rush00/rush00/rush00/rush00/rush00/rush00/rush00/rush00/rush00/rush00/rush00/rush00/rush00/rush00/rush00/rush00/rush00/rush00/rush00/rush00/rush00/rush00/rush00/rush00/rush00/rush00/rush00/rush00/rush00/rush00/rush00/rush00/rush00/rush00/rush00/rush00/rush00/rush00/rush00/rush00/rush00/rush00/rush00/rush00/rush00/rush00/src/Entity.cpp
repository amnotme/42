/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:50:54 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 06:22:53 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Entity::Entity(void) :
	_hp(1),
	_speed(30),
	_nbullets(0),
	_move(0),
	_shoot(0)
{
	for (int i = 0; i < 25; i++)
		this->_bullets[i] = nullptr;
}

Entity::Entity(Entity const &obj)
{
	*this = obj;
	return ;
}

Entity::~Entity( void )
{
	for (int i = 0; i < this->_nbullets; i++)
		delete (this->_bullets[i]);
}

Entity		&Entity::operator=(Entity const &obj)
{
	this->_hp = obj.getHp();
	this->_posX = obj.getPosX();
	this->_posY = obj.getPosY();
	this->_speed = obj.getSpeed();
	return (*this);
}

int			Entity::getHp(void) const
{
	return this->_hp;
}

void		Entity::setHp(int const hp)
{
	this->_hp = hp;
}

int			Entity::getSpeed(void) const
{
	return this->_speed;
}

void		Entity::setSpeed(int const speed)
{
	this->_speed = speed;
}

char const *const *Entity::getSprite(void) const
{
	return (this->_sprite);
}

int			Entity::getSpriteLength(void) const
{
	return (this->_spriteLength);
}

int			Entity::getSpriteWidth(void) const
{
	return (this->_spriteWidth);
}

int			Entity::getPosX(void) const
{
	return this->_posX;
}

void		Entity::setPosX(int posX)
{
	this->_posX = posX;
}

int			Entity::getPosY(void) const
{
	return this->_posY;
}

void		Entity::setPosY(int posY)
{
	this->_posY = posY;
}

int			Entity::getDir(void) const
{
	return (this->_dir);
}

void		Entity::setDir(int dir)
{
	this->_dir = dir;
}

bool		Entity::canMove(void) const
{
	return (Game::getGame()->getTicks() >= this->_move);
}

int			Entity::advance(void)
{
	Game const	*game = Game::getGame();
	int			dir;
	int			length;

	if (!this->canMove())
		return (0);
	dir = this->getDir();
	length = this->getSpriteLength() / 2;
	if (dir > 0 && this->getPosY() == game->getWindow()->getLines() - length - 1)
		return (1);
	else if (this->getPosY() == length)
		return (1);
	this->setPosY(this->getPosY() + dir);
	return (0);
}

Projectile *const	*Entity::getBullets(void) const
{
	return (this->_bullets);
}

int			Entity::getNumBullets(void) const
{
	return (this->_nbullets);
}

void		Entity::removeBullet(void)
{
	Projectile	*tmp;
	int			i;

	i = 0;
	tmp = this->_bullets[0];
	while (i < this->_nbullets)
	{
		this->_bullets[i] = this->_bullets[(i + 1) % 25];
		++i;
	}
	this->_bullets[i % 25] = tmp;
	--this->_nbullets;
}

bool		Entity::canShoot(void) const
{
	return (Game::getGame()->getTicks() >= this->_shoot);
}

void		Entity::shoot(int dir)
{
	Projectile	*bullet;

	if (!this->canShoot() || this->_nbullets == 25)
		return ;
	if (!this->_bullets[this->_nbullets])
		this->_bullets[this->_nbullets] = new Projectile();
	bullet = this->_bullets[this->_nbullets++];
	bullet->setPosX(this->getPosX());
	bullet->setPosY(this->getPosY());
	bullet->setDir(dir);
	this->_shoot = Game::getGame()->getTicks() + 5;
}
