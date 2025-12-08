/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:33:51 by lomont            #+#    #+#             */
/*   Updated: 2025/12/08 00:33:47 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Canonical form

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Alban", 145, 137), target( "Bokoblin" ) {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& setTarget ) : AForm("ShrubberyCreationForm", 145, 137), target( setTarget ) {
	std::cout << "Specific ShrubberyCreationForm constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm(src.getName(), src.getGradeSign(), src.getGradeExec()), target ( src.target ) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (&other != this) {
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

//Method

void ShrubberyCreationForm::execForm( void ) const {
	std::ofstream	file;
	std::string		filename;

	filename = target + "_shrubbery";
	file.open(filename.c_str());
	if (file) {
		file << "   oxoxoo    ooxoo" << std::endl;
		file << " ooxoxo oo  oxoxooo" << std::endl;
		file << "oooo xxoxoo ooo ooox" << std::endl;
		file << "oxo o oxoxo  xoxxoxo" << std::endl;
		file << " oxo xooxoooo o ooo" << std::endl;
		file << "   ooo\\oo\\  /o/o" << std::endl;
		file << "       \\  \\/ /" << std::endl;
		file << "        |   /" << std::endl;
		file << "        |  |" << std::endl;
		file << "        | D|" << std::endl;
		file << "        |  |" << std::endl;
		file << "        |  |" << std::endl;
		file << " ______/____\\____" << std::endl;
		file.close();
	}
	else
		std::cerr << "Error creating/opening file!" << std::endl;
	return ;
}

