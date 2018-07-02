/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rock.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 01:58:30 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 05:21:17 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Rock::Rock(void)
{
	this->setSpeed(45);
	this->_sprite[0] = " # ";
	this->_sprite[1] = "###";
	this->_sprite[2] = " # ";
	this->_spriteLength = 3;
	this->_spriteWidth = 3;
}

Rock::~Rock( void )
{
	return ;
}
