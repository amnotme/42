/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:31:28 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/03 20:31:29 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>


Form::Form( std::string const name, bool sign, int const gradeSign, int const gradeExec )
: _name( name ), _sign( sign ), _gradeSign( gradeSign ), _gradeExec( gradeExec	) {
	std::cout << "\033[1;34mConstructor Called\033[0m" << std::endl;
	if (gradeSign < 1 || gradeExec < 1) {
		throw( Form::GradeTooHighExeption());
	} else if ( gradeSign > 150 || gradeExec > 150 ) {
		throw( Form::GradeTooLowExeption());
	} else {
		this->_name = name;
		this->_gradeSign = gradeSign;
		this->_gradeExec = gradeExec;
		this->_sign = false;
	}
	return ;
}

Form::Form( Form const & other ) {
	*this = other;
	return ;
}

Form::~Form( void ) {
	std::cout << "\033[1;34mDestructor Called\033[0m" << std::endl;
	return ;
}

Form &Form::operator=( Form const & rhs ) {
	this->_name = rhs._name;
	this->_sign = rhs._sign;
	this->_gradeSign = rhs._gradeSign;
	this->_gradeExec = rhs._gradeExec;
	return (*this);
}

//setters

std::string 	Form::getName( void ) const {
	return (this->_name);
}

bool 					Form::getSign( void ) const {
	return (this->_sign);
}

int 					Form::getGradeSign( void ) const {
	return (this->_gradeSign);
}

int 					Form::getGradeExec( void ) const {
	return (this->_gradeExec);
}

//setters

void 					Form::setName( std::string const name ) {
	this->_name = name;
}

void 					Form::setSign( bool sign ) {
	this->_sign = sign;
}

// member Functions

void 					Form::setGradeSign( int const gradeSign ) {
	if (gradeSign < 1) {
		throw(GradeTooHighExeption());
	} else if (gradeSign > 150) {
		throw(GradeTooLowExeption());
	} else {
		this->_gradeSign = gradeSign;
	}
}

void 					Form::setGradeExec( int const gradeExec ) {
	if (gradeExec < 1) {
		throw(GradeTooHighExeption());
	} else if (gradeExec > 150) {
		throw(GradeTooLowExeption());
	} else {
		this->_gradeExec = gradeExec;
	}
}

bool 					Form::beSigned( Bureaucrat const &obj )  {
	if (obj.getGrade() < this->_gradeSign) {
		return (true);
	}	else {
		throw(GradeTooLowExeption());
	}
	return (false);
}

//GradeTooLowExeption
Form::GradeTooLowExeption::GradeTooLowExeption( void ) {
	 return ;
}

Form::GradeTooLowExeption::GradeTooLowExeption( Form::GradeTooLowExeption const & other ) {
	*this = other;
	return ;
}

Form::GradeTooLowExeption::~GradeTooLowExeption( void ) throw() {
	return ;
}

Form::GradeTooLowExeption &Form::GradeTooLowExeption::operator=( Form::GradeTooLowExeption const & rhs ) {
	static_cast< void >(rhs);
	return (*this);
}

const char *Form::GradeTooLowExeption::what() const throw() {
    return ("\033[1;31mForm cannot be signed because Bureaucrat's Grade is Too Low\033[0m");
}

//GradeTooHigh
Form::GradeTooHighExeption::GradeTooHighExeption( void ) {
	return ;
}

Form::GradeTooHighExeption::GradeTooHighExeption( GradeTooHighExeption const & other ) {
	*this = other;
	return ;
}

Form::GradeTooHighExeption::~GradeTooHighExeption( void ) throw() {
	 return ;
}

Form::GradeTooHighExeption &Form::GradeTooHighExeption::operator=( GradeTooHighExeption const & rhs )  {
	static_cast< void >(rhs);
	return (*this);
}

const char *Form::GradeTooHighExeption::what() const throw() {
    return ("\033[1;31mToo High...\033[0m");
}


//ostream
std::ostream &operator<< (std::ostream &o, Form const &rhs) {
    o << "\033[1;32m" << rhs.getName() << ", Form was signed with a grade higher than  " << rhs.getGradeSign()
			<< "\033[0m" << std::endl;
    return (o);
	}
