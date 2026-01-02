/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:53 by lomont            #+#    #+#             */
/*   Updated: 2026/01/02 16:54:35 by lomont           ###   ########.fr       */
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

Bureaucrat::Bureaucrat( void ) : _name( "Officeman" ), _grade( 150 ) {
	std::cout << "Default Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( const std::string& SetName, int SetGrade ) : _name( SetName ) {
	std::cout << "Specific Bureaucrat constructor called" << std::endl;

	if (SetGrade < 1)
		throw GradeTooHighException();
	if (SetGrade > 150 )
		throw GradeTooLowException();

	_grade = SetGrade;
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src) : _name( src._name ), _grade( src._grade ) {
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other) {
	if (&other != this) {
		this->_grade = other._grade;
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
	if ((_grade - 1) < 1)
		throw GradeTooHighException();
	_grade--;
	return ;
}

void Bureaucrat::DecrementGrade( void ) {
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	_grade++;
	return ;
}

//Definition of getters

const std::string& Bureaucrat::getName( void ) const {
	return (this->_name);
}

int Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

//Operator << overload

std::ostream& operator<<(std::ostream& os, Bureaucrat& c) {
	os << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
	return (os);
}

