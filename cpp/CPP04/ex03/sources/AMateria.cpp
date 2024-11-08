/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:50:58 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:50:59 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called!" << std::endl;
	this->type = "No type";
}

AMateria::AMateria(std::string const &tp): type(tp)
{
	std::cout << "AMateria type constructor called!" << std::endl;
}

AMateria::AMateria(const AMateria &amateria)
{
	std::cout << "AMateria copy constructor called!" << std::endl;
	*this = amateria;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
	std::cout << "AMateria copy assignment operator called!" << std::endl;
	this->type = amateria.type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called, memory address = " << this << std::endl;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* does nothing to " << target.getName() << " *" << std::endl;
}

std::string const	&AMateria::getType(void) const
{
	return (this->type);
}
