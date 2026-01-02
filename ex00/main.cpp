/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:55 by lomont            #+#    #+#             */
/*   Updated: 2026/01/02 16:54:24 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {

	//bad grade (too low) initialization
	try
	{
		Bureaucrat e("Helene", -151);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "!! catching Bureaucrat::GradeTooHighException !!\n" << e.what() << std::endl;
	}

	//bad grade (too high) initialization
	try
	{
		Bureaucrat e("Helene", 200);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "!! catching Bureaucrat::GradeTooLowException !!\n" << e.what() << std::endl;
	}

	//good grade initialization
	try
	{
		Bureaucrat e("Alban", 67);
		std::cout << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//Increment into bad grade
	try
	{
		Bureaucrat e("IT", 1);
		std::cout << "Voici " << e << std::endl;
		e.IncrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "!! catching Bureaucrat::GradeTooHighException !!\n" << e.what() << std::endl;
	}

	//Decrement into bad grade
	try
	{
		Bureaucrat e("Kave", 150);
		std::cout << "Voici " << e << std::endl;
		e.DecrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "!! catching Bureaucrat::GradeTooLow Exception !!\n" << e.what() << std::endl;
	}

	return (0);
}
