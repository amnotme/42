/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:05:42 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 05:20:44 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Projectile.hpp"

Projectile::Projectile(void)
{
	this->setSpeed(5);
	this->_sprite[0] = "|";
	this->_spriteLength = 1;
	this->_spriteWidth = 1;
}

Projectile::~Projectile(void)
{
	return ;
}
