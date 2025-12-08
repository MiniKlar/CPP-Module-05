/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:51 by lomont            #+#    #+#             */
/*   Updated: 2025/12/08 01:04:21 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
				virtual ~GradeTooHighException() throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
				virtual ~GradeTooLowException() throw();
		};

		//Canonical form

		Bureaucrat();
		Bureaucrat(const std::string& SetName, int SetGrade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		//Incrementation & decrementation

		void	IncrementGrade( void );
		void	DecrementeGrade( void );

		//Getters

		const std::string& 	getName( void ) const;
		int 				getGrade( void ) const;

		//Sign form

		void signForm(AForm& f);

		//Fuction to execute the form

		void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& c);

#endif
