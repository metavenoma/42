/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:49:16 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:49:17 by rverona-         ###   ########.fr       */
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
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << CARAMEL << "Dog" << PINK << " copy assignment operator called!" << RESET << std::endl;
	type = dog.getType();
	this->brain = dog.brain;
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
