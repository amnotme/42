/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 01:57:42 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 05:01:09 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Enemy::Enemy(void)
{
	Game const	*game = Game::getGame();

	this->setPosX((std::rand() % (game->getWindow()->getCols() - 2)) + 1);
	this->setPosY(-5);
	this->_sprite[0] = "###";
	this->_sprite[1] = " # ";
	this->_spriteLength = 2;
	this->_spriteWidth = 3;
}

Enemy::~Enemy(void)
{
	return ;
}
