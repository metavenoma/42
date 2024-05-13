/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:16 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:17 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
	std::cout << HOT_PINK << "Animal" << PINK << " default constructor called!" << RESET << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << HOT_PINK << "Animal" << PINK << " copy constructor called!" << RESET << std::endl;
	*this = animal;
}

Animal& Animal::operator=(const Animal &animal)
{
	std::cout << HOT_PINK << "Animal" << PINK << " copy assignment operator called!" << RESET << std::endl;
	type = animal.getType();
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << HOT_PINK << "Animal" << ORANGE << " destructor called!" << RESET << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << HOT_PINK << "Animal" << BLUE << " makes a weird sound!" << RESET << std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}
