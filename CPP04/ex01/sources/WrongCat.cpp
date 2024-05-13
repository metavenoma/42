/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:33 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:34 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << DARK_YELLOW << "Wrong Cat" << PINK << " default constructor called!" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongcat)
{
	std::cout << DARK_YELLOW << "Wrong Cat" << PINK << " copy constructor called!" << RESET << std::endl;
	*this = wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	std::cout << DARK_YELLOW << "Wrong Cat" << PINK << " copy assignment operator called!" << RESET << std::endl;
	type = wrongcat.getType();
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << DARK_YELLOW << "Wrong Cat" << ORANGE << " destructor called!" << RESET << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << DARK_YELLOW << "Wrong Cat" << BLUE << " meows weirdly" << RESET << std::endl;
}
