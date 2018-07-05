/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:13:08 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/03 00:13:09 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <stdexcept>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat {

public:
	Bureaucrat( std::string name, int grade );
	Bureaucrat( Bureaucrat const & other );
	~Bureaucrat( void );
	Bureaucrat &operator=( Bureaucrat const & rhs );

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

	// getters

	std::string getName( void ) const ;
	int					getGrade( void ) const ;

	// setters

	void 				setName( std::string name );
	void  			setGrade( int grade );

	// memeber functions

	void				incrementGrade( void );
	void				decrementGrade( void );
	void 				signForm( Form form );
  void 				executeForm( Form const & form );
private:
	std::string 	_name;
	int						_grade;

};
std::ostream  &operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif
