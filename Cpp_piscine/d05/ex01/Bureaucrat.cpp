/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:12:35 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/03 00:12:36 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name( name ), _grade( grade) {
	std::cout << "\033[1;35mConstructor called\033[0m" << std::endl;
	if (grade < 0) {
		throw( Bureaucrat::GradeTooHighExeption());
	} else if (grade > 150) {
		throw( Bureaucrat::GradeTooLowExeption());
	} else {
		this->_name = name;
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const & other ) {
	*this = other;
	return ;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "\033[1;35mDestructor called\033[0m" << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const & rhs ) {
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	return (*this);
}

//getters

std::string Bureaucrat::getName( void ) const {
	return (this->_name);
}

int					Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

// setters

void 				Bureaucrat::setName( std::string name ) {
	this->_name = name;
}

void 				Bureaucrat::setGrade( int grade ) {
	this->_grade = grade;
}

// memeber functions

void 				Bureaucrat::incrementGrade( void ) {
	if (this->_grade - 1 < 1) {
		throw( Bureaucrat::GradeTooHighExeption());
	} else {
		this->_grade = this->_grade - 1;
	}
}

void 				Bureaucrat::decrementGrade( void ) {
	if (this->_grade + 1 > 150) {
		throw( Bureaucrat::GradeTooLowExeption());
	} else {
		this->_grade = this->_grade + 1;
	}
}

void 				Bureaucrat::signForm( Form form ) {
	if (form.beSigned( *this )) {
		std::cout << "\033[1;32m" << this->_name << " signs "
		 					<< form.getName() << "\033[0m" << std::endl;
	} else {
		std::cout << "\033[1;32m" << this->_name << " cannot sign "
		 					<< form.getName() << "\033[0mbecause grade is "
							<< this->_grade << std::endl;
	}
}
// GradeTooLowExeption class
Bureaucrat::GradeTooLowExeption::GradeTooLowExeption( void ) {
	 return ;
}

Bureaucrat::GradeTooLowExeption::GradeTooLowExeption( Bureaucrat::GradeTooLowExeption const & other ) {
	*this = other;
	return ;
}

Bureaucrat::GradeTooLowExeption::~GradeTooLowExeption( void ) throw() {
	return ;
}

Bureaucrat::GradeTooLowExeption &Bureaucrat::GradeTooLowExeption::operator=( Bureaucrat::GradeTooLowExeption const & rhs ) {
	static_cast< void >(rhs);
	return (*this);
}

const char *Bureaucrat::GradeTooLowExeption::what() const throw() {
    return ("\033[1;31mToo Low...\033[0m");
}



// //GradeTooHighExeption

Bureaucrat::GradeTooHighExeption::GradeTooHighExeption( void ) {
	return ;
}

Bureaucrat::GradeTooHighExeption::GradeTooHighExeption( GradeTooHighExeption const & other ) {
	*this = other;
	return ;
}

Bureaucrat::GradeTooHighExeption::~GradeTooHighExeption( void ) throw() {
	 return ;
}

Bureaucrat::GradeTooHighExeption &Bureaucrat::GradeTooHighExeption::operator=( GradeTooHighExeption const & rhs )  {
	static_cast< void >(rhs);
	return (*this);
}

const char *Bureaucrat::GradeTooHighExeption::what() const throw() {
    return ("\033[1;31mToo High...\033[0m");
}

std::ostream &operator<< (std::ostream &o, Bureaucrat const &rhs) {
    o << "\033[1;32m" << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
			<< "\033[0m" << std::endl;
    return (o);
}
