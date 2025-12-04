/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:55 by lomont            #+#    #+#             */
/*   Updated: 2025/12/05 00:41:09 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	try
	{
		Bureaucrat e("Helene", -151);
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "catching Bureaucrat::GradeTooLowException \n  " << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
