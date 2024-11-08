/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:49:04 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:49:05 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("AAnimal")
{
	std::cout << HOT_PINK << "AAnimal" << PINK << " default constructor called!" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &aanimal)
{
	std::cout << HOT_PINK << "AAnimal" << PINK << " copy constructor called!" << RESET << std::endl;
	*this = aanimal;
}

AAnimal& AAnimal::operator=(const AAnimal &aanimal)
{
	std::cout << HOT_PINK << "AAnimal" << PINK << " copy assignment operator called!" << RESET << std::endl;
	type = aanimal.getType();
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << HOT_PINK << "AAnimal" << ORANGE << " destructor called!" << RESET << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << HOT_PINK << "AAnimal" << BLUE << " makes a weird sound!" << RESET << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (type);
}
