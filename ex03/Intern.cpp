/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 01:49:51 by lomont            #+#    #+#             */
/*   Updated: 2025/12/08 02:50:08 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//Canonical form

Intern::Intern( void ) {
	std::cout << "Default Intern constructor called!" << std::endl;
	return ;
}

Intern::Intern( const Intern& src ) {
	(void) src;
	std::cout << "Intern copy constructor called" << std::endl;
	return ;
}

Intern& Intern::operator=(const Intern& other) {
	(void) other;
	std::cout << "Intern assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern( void ) {
	std::cout << "Intern destructor called!" << std::endl;
	return ;
}

//Function to let the Intern create the form

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
	int	i;
	AForm* formCreated;
	std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (i = 0; i < 3 && formName != form[i]; i++) ;

	if (i == 3) {
		std::cout << "Intern is trying to create an inexistent form, we will consider firing him very soon..." << std::endl;
		return (NULL);
	}

	switch (i)
	{
		case 0:
			formCreated = new ShrubberyCreationForm(formTarget);
			break;
		case 1:
			formCreated = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			formCreated = new PresidentialPardonForm(formTarget);
			break;
		default:
			return (NULL);
	}

	std::cout << "Intern created " << formCreated->getName() << std::endl;
	return (formCreated);
}
