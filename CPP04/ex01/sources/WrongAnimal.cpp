/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:30 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:31 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
	std::cout << RED << "Wrong Animal" << PINK << " default constructor called!" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
	std::cout << RED << "Wrong Animal" << PINK << " copy constructor called!" << RESET << std::endl; 
	*this = wronganimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
	std::cout << RED << "Wrong Animal" << PINK << " copy assignment operator called!" << RESET << std::endl;
	type = wronganimal.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "Wrong Animal" << ORANGE << " destructor called!" << RESET << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << RED << "Wrong Animal" << BLUE << " makes a weird as hell random sound" << RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}
