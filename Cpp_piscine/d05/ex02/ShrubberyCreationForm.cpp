/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 22:45:55 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/03 22:45:57 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include "ShrubberyCreationForm.hpp"

int const		ShrubberyCreationForm::_sign = 145;
int const		ShrubberyCreationForm::_exec = 137;

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, "Shrubbery", ShrubberyCreationForm::_sign, ShrubberyCreationForm::_exec ) {
		this->_target = target;
		return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src ) : Form("", "Shrubbery", ShrubberyCreationForm::_sign, ShrubberyCreationForm::_exec) {
    *this = src;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= ( ShrubberyCreationForm const  & rhs) {
    static_cast<void>(rhs);
    return (*this);
}

std::string ShrubberyCreationForm::getTarget( void ) const {
	return (this->_target);
}

void ShrubberyCreationForm::execute( Bureaucrat const &executor) const {
    std::ofstream  of;

    Form::execute(executor);
    of.open(getTarget() + "_shrubbery",
                 std::ofstream::out | std::ofstream::trunc);
    if (of.fail()) {
        std::cerr << "Error openning the outfile ( of )" << std::endl;
		 }

		of << "###########################'`################################ " << std::endl;
		of << "###########################  V##'############################ " << std::endl;
		of << "#########################V'  `V  ############################ " << std::endl;
		of << "########################V'      ,############################ " << std::endl;
		of << "#########`#############V      ,A###########################V " << std::endl;
		of << "########' `###########V      ,###########################V',# " << std::endl;
		of << "######V'   ###########l      ,####################V~~~~'',### " << std::endl;
		of << "#####V'    ###########l      ##P' ###########V~~'   ,A####### " << std::endl;
		of << "#####l      d#########l      V'  ,#######V~'       A######### " << std::endl;
		of << "#####l      ##########l         ,####V''         ,########### " << std::endl;
		of << "#####l        `V######l        ,###V'   .....;A############## " << std::endl;
		of << "#####A,         `######A,     ,##V' ,A####################### " << std::endl;
		of << "#######A,        `######A,    #V'  A########'''''##########'' " << std::endl;
		of << "##########,,,       `####A,           `#''           '''  ,,, " << std::endl;
		of << "#############A,                               ,,,     ,###### " << std::endl;
		of << "######################oooo,                 ;####, ,######### " << std::endl;
		of << "##################P'                   A,   ;#####V########## " << std::endl;
		of << "#####P'    ''''       ,###             `#,     `V############ " << std::endl;
		of << "##P'                ,d###;              ##,       `V######### " << std::endl;
		of << "##########A,,   #########A              )##,    ##A,..,ooA### " << std::endl;
		of << "#############A, Y#########A,            )####, ,############# " << std::endl;
		of << "###############A ############A,        ,###### ############## " << std::endl;
		of << "###############################       ,#######V############## " << std::endl;
		of << "###############################      ,####################### " << std::endl;
		of << "##############################P    ,d######################## " << std::endl;
		of << "##############################'    d######################### " << std::endl;
		of << "##############################     ########################## " << std::endl;
		of << "##############################     ########################## " << std::endl;
		of << "#############################P     ########################## " << std::endl;
		of << "#############################'     ########################## " << std::endl;
		of << "############################P      ########################## " << std::endl;
		of << "###########################P'     ;########################## " << std::endl;
		of << "###########################'     ,########################### " << std::endl;
		of << "##########################       ############################ " << std::endl;
		of << "#########################       ,############################ " << std::endl;
		of << "########################        d###########P'    `Y######### " << std::endl;
		of << "#######################        ,############        ######### " << std::endl;
		of << "######################        ,#############        ######### " << std::endl;
		of << "#####################        ,##############b.    ,d######### " << std::endl;
		of << "####################        ,################################ " << std::endl;
		of << "###################         ################################# " << std::endl;
		of << "##################          #######################P'  `V##P' " << std::endl;
		of << "#######P'     `V#           ###################P' " << std::endl;
		of << "#####P'                    ,#################P' " << std::endl;
		of << "###P'                      d##############P'' " << std::endl;
		of << "##P'                       V##############' " << std::endl;
		of << "#P'                         `V###########' " << std::endl;
		of << " #'                             `V##P' " << std::endl;
		of << std::endl;
		of.close();
		    return ;
}
