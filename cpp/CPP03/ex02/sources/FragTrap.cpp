/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          FragTrap.cpp                                  ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("Default", 100, 100, 30)
{
	std::cout << "FragTrap " << this->name << " constructor called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap): ClapTrap(fragtrap.name, fragtrap.HP, fragtrap.EP, fragtrap.AD)
{
	std::cout << "FragTrap " << fragtrap.name << " copy constructor called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	if (this != &fragtrap)
	{
		std::cout << "FragTrap " << fragtrap.name << " copied into " << this->name << std::endl;
		this->name = fragtrap.name;
		this->HP = fragtrap.HP;
		this->EP = fragtrap.EP;
		this->AD = fragtrap.AD;
	}
	return (*this);
}

FragTrap::FragTrap(std::string name): ClapTrap (name, 100, 100, 30)
{
	std::cout << "FragTrap " << this->name << " constructor called!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " wants to high five!" << std::endl;
}
