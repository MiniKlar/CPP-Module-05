/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:34:05 by lomont            #+#    #+#             */
/*   Updated: 2025/12/08 00:33:51 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const std::string& setTarget );
		ShrubberyCreationForm( const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
		~ShrubberyCreationForm( void );
		void execForm( void ) const;
};

#endif
