/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:33:59 by lomont            #+#    #+#             */
/*   Updated: 2025/12/08 00:56:50 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string& setTarget );
		RobotomyRequestForm( const RobotomyRequestForm& src );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
		~RobotomyRequestForm( void );
		void execForm( void ) const;
};

#endif
