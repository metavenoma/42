/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:21 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:22 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	this->brain = new Brain();
	std::cout << YELLOW << "Cat" << PINK << " default constructor called!" << RESET << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << YELLOW << "Cat" << PINK << " copy constructor called!" << RESET << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << YELLOW << "Cat" << PINK << " copy assignment operator called!" << RESET << std::endl;
	type = cat.getType();
	this->brain = cat.brain;
	return (*this);
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << YELLOW << "Cat" << ORANGE << " destructor called!" << RESET << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << "Cat" << BLUE << " puuuuuurrrrrsssss and meoooowsss" << RESET << std::endl;
}

Brain&	Cat::getBrain(void) const
{
	return (*brain);
}
