/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:55 by lomont            #+#    #+#             */
/*   Updated: 2026/01/02 17:06:43 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

	//Bureaucrat can't sign
	try
	{
		Bureaucrat e("Me", 149);
		std::cout << e << std::endl;

		Form f("Rep", 148, 140);
		std::cout << f << std::endl;

		e.signForm(f);

		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//Bureaucrat can sign
	try
	{
		Bureaucrat e("Me", 67);
		std::cout << e << std::endl;

		Form f("Rep", 148, 140);
		std::cout << f << std::endl;

		e.signForm(f);

		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
