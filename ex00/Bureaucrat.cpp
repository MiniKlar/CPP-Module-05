/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:53 by lomont            #+#    #+#             */
/*   Updated: 2025/12/05 00:40:57 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Definition of GradeTooHigh & TooLow class

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Error: Grade exceeded the maximum Grade possible (1)");
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {
	return ;
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Error: Grade exceeded the minimal Grade possible (150)");
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {
	return ;
}

// Definition of the Canonical form

Bureaucrat::Bureaucrat( void ) : Name( "Officeman" ), Grade( 150 ) {
	std::cout << "Default Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( std::string SetName, int SetGrade ) : Name( SetName ) {
	std::cout << "Specific Bureaucrat constructor called" << std::endl;

	if (SetGrade < 1)
		throw GradeTooHighException();
	if (SetGrade > 150 )
		throw GradeTooLowException();

	Grade = SetGrade;
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src) : Name( src.Name ), Grade( src.Grade ) {
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other) {
	if (&other != this) {
		this->Name = other.Name;
		this->Grade = other.Grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
	return ;
}

//Definition of Incr/Decr functions

void Bureaucrat::IncrementGrade( void ) {
	if ((Grade - 1) < 1)
		throw GradeTooHighException();
	Grade--;
	return ;
}

void Bureaucrat::DecrementeGrade( void ) {
	if ((Grade + 1) > 150)
		throw GradeTooHighException();
	Grade++;
	return ;
}

//Definition of getters

std::string const Bureaucrat::getName( void ) {
	return (this->Name);
}

int Bureaucrat::getGrade( void ) {
	return (this->Grade);
}

//Operator << overload

std::ostream& operator<<(std::ostream& os, Bureaucrat& c) {
	os << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
	return (os);
}

