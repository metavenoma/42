/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:18 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:19 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << BLUE << "Brain" << PINK << " default constructor called!" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << BLUE << "Brain" << PINK << " copy constructor called!" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << BLUE << "Brain" << PINK << " copy assignment operator called!" << std::endl;
	std::copy(brain.ideas, brain.ideas + 100, this->ideas);
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << BLUE << "Brain" << ORANGE << " destructor called!" << std::endl;
}

