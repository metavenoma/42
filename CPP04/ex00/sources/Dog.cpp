/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:47:37 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:47:38 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	std::cout << CARAMEL << "Dog" << PINK << " default constructor called!" << RESET << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << CARAMEL << "Dog" << PINK << " copy constructor called!" << RESET << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << CARAMEL << "Dog" << PINK << " copy assignment operator called!" << RESET << std::endl;
	type = dog.getType();
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << CARAMEL << "Dog" << ORANGE << " destructor called!" << RESET << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << CARAMEL << "Dog" << BLUE << " barks violently then whimpers cutely" << RESET << std::endl;
}
