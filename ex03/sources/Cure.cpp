/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:51:04 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:51:05 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Ice default constructor called!" << std::endl;
}

Cure::Cure(const Cure &cure)
{
	std::cout << "Cure copy constructor called!" << std::endl;
	*this = cure;
}

Cure	&Cure::operator=(const Cure &cure)
{
	std::cout << "Cure copy assignment operator called!" << std::endl;
	this->type = cure.type;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called, memory address = " << this << std::endl;
}

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName()<< "'s wounds *" << std::endl;
}
