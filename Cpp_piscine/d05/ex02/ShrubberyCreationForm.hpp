/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 22:46:02 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/03 22:46:04 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <fstream>

# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form {
	public:
    ShrubberyCreationForm( void );
    ShrubberyCreationForm( std::string target );
    ShrubberyCreationForm( ShrubberyCreationForm const & other );
    ~ShrubberyCreationForm( void );
    ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &rhs );

		//getter

		std::string 						getTarget( void ) const ;
		virtual void 						execute( const Bureaucrat &executor ) const ;

	private:
		std::string 	const			_target;
    static int const				_sign;
    static int const				_exec;
};

#endif
