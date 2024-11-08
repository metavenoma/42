/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:51:01 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:51:02 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name("No name"), index(0)
{
	std::cout << "Character default constructor called!" << std::endl;
	for (int i = 0; i < SLOTS; i++)
		this->inventory[i] = NULL;
	this->floor = NULL;
	this->floor = new Floor();
}

Character::Character(std::string name): _name(name), index(0)
{
	std::cout << "Character name constructor called!" << std::endl;
	for (int i = 0; i < SLOTS; i++)
		this->inventory[i] = NULL;
	this->floor = NULL;
	this->floor = new Floor();
}

Character::Character(const Character &character): _name(character._name), index(character.index)
{
	std::cout << "Character copy constructor called!" << std::endl;
	for (int i = 0; i < SLOTS; i++)
	{
		this->inventory[i] = NULL;
		if (character.inventory[i] != NULL)
			this->inventory[i] = character.inventory[i]->clone();
	}
	this->floor = new Floor(*character.floor);
}

Character &Character::operator=(const Character &character)
{
	std::cout << "Character copy assignment operator called!" << std::endl;

	if (this != &character)
	{
		for (int i = 0; i < SLOTS; i++)
		{
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			this->inventory[i] = NULL;
			if (character.inventory[i] != NULL)
				this->inventory[i] = character.inventory[i]->clone();
		}
		this->index = character.index;
		if (this->floor != NULL)
			delete this->floor;
		if (character.floor != NULL)
			this->floor = new Floor(*character.floor);
	}
	return (*this);
}

Character::~Character(void)
{
	std::cout << "Character destructor called, memory address = " << this << std::endl;
	for (int i = 0; i < SLOTS; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	if (this->floor != NULL)
		delete this->floor;
}

const std::string	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (this->index == -1)
	{
		if (m != NULL)
			delete m;
		return ;
	}
	while (this->index < SLOTS)
	{
		if (this->inventory[this->index] == NULL)
		{
			this->inventory[this->index] = m;
			break ;
		}
		this->index++;
	}
	if (this->index >= SLOTS)
		this->index = -1;
}

void	Character::unequip(int idx)
{
	if (idx < SLOTS && idx >= 0 && this->inventory[idx] != NULL)
	{
		if (this->floor == NULL)
			this->floor = new Floor();
		this->floor->addNode(this->inventory[idx]);
		this->inventory[idx] = NULL;
		if (this->index > 0)
			this->index--;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < SLOTS && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}
