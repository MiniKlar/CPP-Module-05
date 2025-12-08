/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:33:53 by lomont            #+#    #+#             */
/*   Updated: 2025/12/08 01:01:02 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Canonical form

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Alban", 72, 45), target( "Bokoblin" ) {
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& setTarget ) : AForm("RobotomyRequestForm", 72, 45), target( setTarget ) {
	std::cout << "Specific RobotomyRequestForm constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : AForm(src.getName(), src.getGradeSign(), src.getGradeExec()), target ( src.target ) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (&other != this) {
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

void RobotomyRequestForm::execForm( void ) const {
	int randNumber;

	std::cout << "You can hear some drilling noises below your feet" << std::endl;

	std::srand(std::time(0));
	randNumber = std::rand() % 2;
	if (randNumber == 1)
		std::cout << target << " has been robotomized!" << std::endl;
	else
		std::cout << "The robotomy has failed on " << target << "!" << std::endl;
	return ;
}
