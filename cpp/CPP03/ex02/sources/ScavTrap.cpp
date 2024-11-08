/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          ScavTrap.cpp                                  ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("Default", 100, 50, 20)
{
	std::cout << "Default ScavTrap constructor called!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->name << " ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap(scavtrap.name, scavtrap.HP, scavtrap.EP, scavtrap.AD)
{
	std::cout << "ScavTrap " << scavtrap.name << " copy constructor called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	if (&scavtrap != this)
	{
		std::cout << "ScavTrap " << scavtrap.name << " copied into " << this->name << std::endl;
		this->name = scavtrap.name;
		this->HP = scavtrap.HP;
		this->EP = scavtrap.EP;
		this->AD = scavtrap.AD;
	}
	return (*this);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << this->name << " ScavTrap constructor called!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->HP <= 0)
		std::cout << this->name << " cannot attack, it has 0 HP left!" << std::endl;
	else
	{
		for (int i = 0; i < (int)this->AD; i++)
		{
			if (this->EP <= 0)
			{
				std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->AD << " points of damage!" << std::endl;
				return;
			}
			this->EP--;
		}
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->AD << " points of damage!" << std::endl;
	}

}

void	ScavTrap::guardGate(void)
{
	std::cout << this->name << " ScavTrap is now in gate keeper mode!" << std::endl;
}
