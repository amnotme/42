/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 22:46:23 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/03 22:46:25 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
# include <fstream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & other );
		~RobotomyRequestForm( void );
		RobotomyRequestForm &operator=( RobotomyRequestForm const & rhs );

	private:
		static int const 			_sign;
		static int const 			_exec;

};

# endif
