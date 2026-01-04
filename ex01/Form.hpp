/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:03:23 by lomont            #+#    #+#             */
/*   Updated: 2026/01/02 16:57:19 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
#define	FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
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

		Form( void );
		Form( std::string setName, int setGradeToSign, int setGradeToExec );
		Form( const Form& src);
		Form& operator=( const Form& other);
		~Form( void );

		//Getters
		const std::string&	getName( void ) const;
		bool				getSigned( void ) const;
		int					getGradeSign( void ) const;
		int					getGradeExec( void ) const;

		//Function to sign the form
		void				beSigned(Bureaucrat& c);

};

std::ostream& operator<<(std::ostream& os, Form& f);

#endif
