/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:03:20 by lomont            #+#    #+#             */
/*   Updated: 2025/12/08 01:36:15 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//Definition of GradeTooHigh & TooLow class

const char* AForm::GradeTooHighException::what( void ) const throw() {
	return ("Error: Grade exceeded the maximum Grade possible (1)");
}

AForm::GradeTooHighException::~GradeTooHighException( void ) throw() {
	return ;
}

const char* AForm::GradeTooLowException::what( void ) const throw() {
	return ("Error: Grade exceeded the minimal Grade possible (150)");
}

AForm::GradeTooLowException::~GradeTooLowException( void ) throw() {
	return ;
}

const char* AForm::FormNotSigned::what( void ) const throw() {
	return ("Error: The form is not signed; you can't execute it without signing it!");
}

AForm::FormNotSigned::~FormNotSigned( void ) throw() {
	return ;
}

// Canonical form

AForm::AForm( void ) : _name( "Default Form"), _signed( false ), _gradeToSign( 5 ), _gradeToExec( 10 ) {
	std::cout << "AForm default constructor called" << std::endl;
	return ;
}

AForm::AForm( std::string setName, int setGradeToSign, int setGradeToExec) : _name( setName ), _signed( false ), _gradeToSign( setGradeToSign ), _gradeToExec ( setGradeToExec ) {
	std::cout << "Specific AForm constructor called" << std::endl;
	return ;
}

AForm::AForm( const AForm& src) : _name( src._name ), _signed( src._signed ), _gradeToSign( src._gradeToSign ), _gradeToExec ( src._gradeToExec ) {
	std::cout << "Copy AForm constructor called" << std::endl;
	return ;
}

AForm& AForm::operator=(const AForm& other) {
	if (&other != this) {
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm( void ) {
	std::cout << "AForm destructor called" << std::endl;
	return ;
}

//Definition of getters

const std::string& AForm::getName( void ) const {
	return (_name);
}

bool AForm::getSigned( void ) const {
	return (_signed);
}

int AForm::getGradeSign( void ) const {
	return (_gradeToSign);
}

int AForm::getGradeExec( void ) const {
	return (_gradeToExec);
}

//Definition of the signing function

void AForm::beSigned(Bureaucrat& c) {
	if (c.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
	return ;
}

//Operator << overload

std::ostream& operator<<(std::ostream& os, AForm& f) {
	std::string message;

	message = " is signed";
	if (!f.getSigned())
		message = " is not signed";

	os << "The form " << f.getName() << message << "." << " To be signed, the Bureaucrat needs to be grade ";
	os << f.getGradeSign() << " and to execute it, he needs to be grade " << f.getGradeExec() << ".";
	return (os);
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!_signed)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > _gradeToExec)
		throw Bureaucrat::GradeTooLowException();
	execForm();
	return ;
}
