/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:23 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:24 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	this->brain = new Brain();
	std::cout << CARAMEL << "Dog" << PINK << " default constructor called!" << RESET << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << CARAMEL << "Dog" << PINK << " copy constructor called!" << RESET << std::endl;
	this->Animal::type = dog.type;
	this->brain = new Brain(*dog.brain);
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << CARAMEL << "Dog" << PINK << " copy assignment operator called!" << RESET << std::endl;
	if (this != &dog)
	{
		type = dog.getType();
		this->brain = new Brain (*dog.brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << CARAMEL << "Dog" << ORANGE << " destructor called!" << RESET << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << CARAMEL << "Dog" << BLUE << " barks violently then whimpers cutely" << RESET << std::endl;
}

Brain&	Dog::getBrain(void) const
{
	return (*brain);
}
