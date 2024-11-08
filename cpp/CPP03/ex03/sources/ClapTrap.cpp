/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          ClapTrap.cpp                                  ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Default"), HP(10), EP(10), AD(0)
{
	std::cout << "ClapTrap named Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap): _name(claptrap._name), HP(claptrap.HP), EP(claptrap.EP), AD(claptrap.AD)
{
	std::cout << "ClapTrap " << claptrap._name << " copy constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad): _name(name), HP(hp), EP(ep), AD(ad)
{
	std::cout << "ClapTrap base named " << _name << " constructor called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	if (&claptrap != this)
	{
		std::cout << "Claptrap " << claptrap._name << " copied into " << this->_name << std::endl;
		this->_name = claptrap._name;
		this->HP = claptrap.HP;
		this->EP = claptrap.EP;
		this->AD = claptrap.AD;
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string name): _name(name), HP(10), EP(10), AD(0)
{
	std::cout << "ClapTrap named " << _name << " constructor called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap named " << this->_name << " destructor called!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->HP <= 0)
		std::cout << this->_name << " cannot attack, it has 0 HP left!" << std::endl;
	else
	{
		for (int i = 0; i < (int)this->AD; i++)
		{
			if (this->EP <= 0)
			{
				std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->AD << " points of damage!" << std::endl;
				return;
			}
			this->EP--;
		}
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->AD << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	for (int i = 0; i < (int)amount; i++)
	{
		if (this->HP <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " has no more HP left before taking " << amount << " points of damage" << std::endl;
			return;
		}
		this->HP--;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl; 
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	for (int i = 0; i < (int)amount; i++)
	{
		if (this->EP <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " repairs itself " << i << " points of health! But he has no EP left!" << std::endl;
		}
		this->HP++;
		this->EP--;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself " << amount << " points of health!" << std::endl;
}

int	ClapTrap::getHp(void)
{
	return (this->HP);
}

int	ClapTrap::getEp(void)
{
	return (this->EP);
}

int	ClapTrap::getAd(void)
{
	return (this->AD);
}
