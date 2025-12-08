/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:03:23 by lomont            #+#    #+#             */
/*   Updated: 2025/12/08 01:23:58 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		int	const			_gradeToSign;
		int	const			_gradeToExec;
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

		class FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
				virtual ~FormNotSigned() throw();
			};

		//Canonical form

		AForm( void );
		AForm( std::string setName, int setGradeToSign, int setGradeToExec );
		AForm( const AForm& src);
		AForm& operator=( const AForm& other);
		virtual ~AForm( void );

		//Getters
		const std::string&	getName( void ) const;
		bool				getSigned( void ) const;
		int					getGradeSign( void ) const;
		int					getGradeExec( void ) const;

		//Function to sign the form
		void				beSigned(Bureaucrat& c);

		virtual void execute(Bureaucrat const & executor) const;

		virtual void execForm( void ) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& f);

#endif
