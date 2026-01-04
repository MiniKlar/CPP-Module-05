/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:55 by lomont            #+#    #+#             */
/*   Updated: 2026/01/04 10:42:47 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern feur;
	AForm* formCreated;
	formCreated = feur.makeForm("robotomy request", "Alban");
	Bureaucrat a("Me", 45);
	std::cout << a << std::endl << *formCreated << std::endl;
	a.signForm(*formCreated);
	a.executeForm(*formCreated);
	delete formCreated;
	return 0;
}
