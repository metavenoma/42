/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:51:07 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:51:08 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice default constructor called!" << std::endl;
}

Ice::Ice(const Ice &ice)
{
	std::cout << "Ice copy constructor called!" << std::endl;
	*this = ice;
}

Ice	&Ice::operator=(const Ice &ice)
{
	std::cout << "Ice copy assignment operator called!" << std::endl;
	this->type = ice.type;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called, memory address = " << this << std::endl;
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
