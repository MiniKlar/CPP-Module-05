/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:51 by lomont            #+#    #+#             */
/*   Updated: 2025/12/05 00:40:57 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
	private:
		std::string	Name;
		int		Grade;
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
		Bureaucrat(std::string const SetName, int SetGrade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		//Incrementation & decrementation

		void	IncrementGrade( void );
		void	DecrementeGrade( void );

		//Getters

		std::string const	getName( void );
		int 				getGrade( void );
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& c);


