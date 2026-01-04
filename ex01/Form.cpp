/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:03:20 by lomont            #+#    #+#             */
/*   Updated: 2026/01/02 16:59:03 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//Definition of GradeTooHigh & TooLow class

const char* Form::GradeTooHighException::what( void ) const throw() {
	return ("Error: Grade exceeded the maximum Grade possible (1)");
}

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {
	return ;
}

const char* Form::GradeTooLowException::what( void ) const throw() {
	return ("Error: Grade exceeded the minimal Grade possible (150)");
}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {
	return ;
}

// Canonical form

Form::Form( void ) : _name( "Default Form"), _signed( false ), _gradeToSign( 5 ), _gradeToExec( 10 ) {
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

Form::Form( std::string setName, int setGradeToSign, int setGradeToExec) : _name( setName ), _signed( false ), _gradeToSign( setGradeToSign ), _gradeToExec ( setGradeToExec ) {
	std::cout << "Specific Form constructor called" << std::endl;
	return ;
}

Form::Form( const Form& src) : _name( src._name ), _signed( src._signed ), _gradeToSign( src._gradeToSign ), _gradeToExec ( src._gradeToExec ) {
	std::cout << "Copy Form constructor called" << std::endl;
	return ;
}

Form& Form::operator=(const Form& other) {
	if (&other != this) {
		this->_signed = other._signed;
	}
	return ( *this );
}

Form::~Form( void ) {
	std::cout << "Form destructor called" << std::endl;
	return ;
}

//Definition of getters

const std::string& Form::getName( void ) const {
	return ( _name );
}

bool Form::getSigned( void ) const {
	return ( _signed );
}

int Form::getGradeSign( void ) const {
	return ( _gradeToSign );
}

int Form::getGradeExec( void ) const {
	return ( _gradeToExec );
}

//Definition of the signing function

void Form::beSigned(Bureaucrat& c) {
	if (c.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
	return ;
}

//Operator << overload

std::ostream& operator<<(std::ostream& os, Form& f) {
	std::string message;

	message = " is signed";
	if (!f.getSigned())
		message = " is not signed";

	os << "The form " << f.getName() << message << "." << " To be signed, the Bureaucrat needs to be grade ";
	os << f.getGradeSign() << " and to execute it, he needs to be grade " << f.getGradeExec() << ".";
	return (os);
}

