/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:33:55 by lomont            #+#    #+#             */
/*   Updated: 2025/12/08 01:01:20 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//Canonical form

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Alban", 25, 5), target( "Bokoblin" ) {
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& setTarget ) : AForm("PresidentialPardonForm", 25, 5), target( setTarget ) {
	std::cout << "Specific PresidentialPardonForm constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : AForm(src.getName(), src.getGradeSign(), src.getGradeExec()), target ( src.target ) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (&other != this) {
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return ;
}

//Method

void PresidentialPardonForm::execForm( void ) const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	return ;
}
