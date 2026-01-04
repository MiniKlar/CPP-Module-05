/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:55 by lomont            #+#    #+#             */
/*   Updated: 2026/01/04 10:31:39 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

	//good execution
	Bureaucrat a("Kirby", 137);
	ShrubberyCreationForm test("Metaknight");
	a.executeForm(test);
	a.signForm(test);
	a.executeForm(test);

	Bureaucrat b("T", 45);
	RobotomyRequestForm test1("CT");
	b.executeForm(test1);
	b.signForm(test1);
	b.executeForm(test1);

	Bureaucrat c("Pika", 4);
	PresidentialPardonForm test2("Grookey");
	c.executeForm(test2);
	c.signForm(test2);
	c.executeForm(test2);

	//bad execution
	Bureaucrat d("Alban", 149);
	PresidentialPardonForm test3("450 hours a month");
	d.executeForm(test3);
	d.signForm(test3);
	std::cout << d << std::endl << test3 << std::endl;
	d.executeForm(test3);
	return 0;
}
