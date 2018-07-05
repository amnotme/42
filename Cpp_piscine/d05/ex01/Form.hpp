/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:31:35 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/03 20:31:38 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:
	Form( std::string const name, bool sign, int const gradeSign, int const gradeExec );
	Form( Form const & other );
	~Form( void );
	Form &operator=( Form const & rhs );

	class GradeTooHighExeption : public std::exception {
	public:
		GradeTooHighExeption( void );
		GradeTooHighExeption( GradeTooHighExeption const & other );
		GradeTooHighExeption &operator=( GradeTooHighExeption const & rhs );
		virtual ~GradeTooHighExeption( void ) throw();
		virtual const char *what() const throw();
	};

	class GradeTooLowExeption : public std::exception {
	public:
		GradeTooLowExeption( void );
		GradeTooLowExeption( GradeTooLowExeption const & other );
		GradeTooLowExeption &operator=( GradeTooLowExeption const & rhs );
		virtual ~GradeTooLowExeption( void ) throw();
		virtual const char *what() const throw();
	};

	//getters

	std::string		getName( void ) const ;
	bool					getSign( void ) const ;
	int						getGradeSign( void ) const ;
	int						getGradeExec( void ) const ;

	//setters

	void 					setName( std::string const name ) ;
	void 					setSign( bool sign );

	//member fucntions

	void 					setGradeSign( int const gradeSign );
	void 					setGradeExec( int const gradeExec );
	bool 					beSigned( Bureaucrat const &obj );
	private:
	std::string		_name;
	bool					_sign;
	int						_gradeSign;
	int						_gradeExec;

};

std::ostream  &operator<<(std::ostream &out, Form const &rhs);

#endif
