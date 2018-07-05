/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:25:50 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/04 23:19:32 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Convert.hpp"
#include <iomanip>
#include <cmath>
Convert::Convert( void ) :
   	_input(" "),
	_convertInt(0),
	_convertFloat(0.0f),
	_convertDouble(0.0),
	_convertChar(' ') {
		std::cout << "\033[1;32mDefault Convert constructor called \033[0m"
				  << std::endl;
	}

Convert::Convert( std::string input) : 
	_input( input ),
	_convertInt(0),
	_convertFloat(0.0f),
	_convertDouble(0.0),
	_convertChar(' ') {
		std::cout << "\033[1;32mDefault Convert constructor called \033[0m"
				  << std::endl;
	}

Convert::Convert( Convert const & other ) {
	*this = other;
	return ;
}

Convert::~Convert( void ) {
	std::cout << "\033[1;31mDestructor for Convert called\033[0m" << std::endl;
	return ;
}

Convert	&Convert::operator=( Convert const & rhs ) {
	this->_input = rhs.getInput();
	this->_convertInt = rhs.getInt();
	this->_convertFloat = rhs.getFloat();
	this->_convertDouble = rhs.getDouble();
	this->_convertChar = rhs.getChar();
	return (*this);
}

// getters

std::string 	Convert::getInput( void ) const {
	return (this->_input);
}

int				Convert::getInt( void ) const {
	return (this->_convertInt);
}

float			Convert::getFloat( void ) const {
	return (this->_convertFloat);
}

double			Convert::getDouble( void ) const {
	return (this->_convertDouble);
}

char 			Convert::getChar( void ) const {
	return (this->_convertChar);
}

//

void			Convert::setInput( std::string input ) {
	this->_input = input;
}

void			Convert::setInt( int intVal ) {
	this->_converInt = intVal
}

void			Convert::setFloat( float floatVal ) {
	this->_convertFloat = floatVal
}

void			Convert::setDouble( double doubleVal ) {
	this->_convertDouble = doubleVal;
}

void			Convert::setChar( char charVal ) {
	this->_convertChar = charVal;
}

// member functions

void			Convert::parseInput( char *argument ) {
	setInput(argument);
	std::cout << "input: " << getInput() << std::endl;
	setInt(argument);
	//setFloat(argument);
}
