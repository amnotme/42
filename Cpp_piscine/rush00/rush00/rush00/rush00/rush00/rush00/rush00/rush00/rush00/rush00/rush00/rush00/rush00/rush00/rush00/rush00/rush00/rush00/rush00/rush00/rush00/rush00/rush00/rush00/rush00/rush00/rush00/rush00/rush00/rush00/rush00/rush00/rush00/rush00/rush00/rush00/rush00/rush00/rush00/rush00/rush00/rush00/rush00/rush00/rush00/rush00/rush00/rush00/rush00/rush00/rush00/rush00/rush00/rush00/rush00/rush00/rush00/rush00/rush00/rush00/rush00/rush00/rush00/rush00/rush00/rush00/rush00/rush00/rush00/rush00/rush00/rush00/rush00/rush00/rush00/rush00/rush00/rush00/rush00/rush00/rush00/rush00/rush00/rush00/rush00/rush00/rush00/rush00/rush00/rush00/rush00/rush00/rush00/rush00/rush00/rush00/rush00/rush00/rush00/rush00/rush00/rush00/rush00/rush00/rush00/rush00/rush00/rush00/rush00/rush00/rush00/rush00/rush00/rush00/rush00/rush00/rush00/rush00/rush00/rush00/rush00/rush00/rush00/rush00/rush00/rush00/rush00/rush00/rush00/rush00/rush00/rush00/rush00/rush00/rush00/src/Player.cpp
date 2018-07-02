/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 01:58:09 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 05:33:32 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Player::Player(void) :
	_lives(5),
	_score(0)
{
	this->setSpeed(0);
	this->setPosX(Game::getGame()->getWindow()->getCols() / 2);
	this->setPosY(Game::getGame()->getWindow()->getLines() - 3);
	this->_sprite[0] = " # ";
	this->_sprite[1] = "###";
	this->_spriteLength = 2;
	this->_spriteWidth = 3;
}

Player::~Player(void)
{
	return ;
}

int		Player::getLives(void) const
{
	return (this->_lives);
}

void	Player::setLives(int lives)
{
	this->_lives = lives;
}

int		Player::getScore(void) const
{
	return (this->_score);
}

void	Player::setScore(int score)
{
	this->_score = score;
}

void	Player::moveLeft(void)
{
	int			width;

	width = this->getSpriteWidth() / 2;
	if (!this->canMove()
		|| this->getPosX() == 1 + width)
		return ;
	this->_posX -= 1;
	this->_move = Game::getGame()->getTicks() + this->getSpeed();
}

void	Player::moveRight(void)
{
	int			width;

	width = this->getSpriteWidth() / 2;
	if (!this->canMove()
		|| this->getPosX() == Game::getGame()->getWindow()->getCols() - width - 2)
		return ;
	this->_posX += 1;
	this->_move = Game::getGame()->getTicks() + this->getSpeed();
}

void	Player::moveUp(void)
{
	int			length;

	length = this->getSpriteLength() / 2;
	if (!this->canMove()
		|| this->getPosY() == length)
		return ;
	this->_posY -= 1;
	this->_move = Game::getGame()->getTicks() + this->getSpeed();
}

void	Player::moveDown(void)
{
	int			length;

	length = this->getSpriteLength() / 2;
	if (!this->canMove()
		|| this->getPosY() == Game::getGame()->getWindow()->getLines() - length - 1)
		return ;
	this->_posY += 1;
	this->_move = Game::getGame()->getTicks() + this->getSpeed();
} 
