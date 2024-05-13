/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          DiamondTrap.cpp                               ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->HP = this->FragTrap::getHp();
	this->EP = this->ScavTrap::getEp();
	this->AD = this->FragTrap::getAd();
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap): ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
	this->_name = diamondtrap._name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->HP = diamondtrap.HP;
	this->EP = diamondtrap.EP;
	this->AD = diamondtrap.AD;
	std::cout << "DiamondTrap " << diamondtrap._name << " copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->HP = this->FragTrap::getHp();
	this->EP = this->ScavTrap::getEp();
	this->AD = this->FragTrap::getAd();
	std::cout << "DiamondTrap " << this->_name << " name constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	if (this != &diamondtrap)
	{
		std::cout << "DiamondTrap " << diamondtrap._name << " copied into " << this->_name << std::endl;
		this->_name = diamondtrap._name;
		this->ClapTrap::_name = diamondtrap.ClapTrap::_name;
		this->HP = diamondtrap.HP;
		this->EP = diamondtrap.EP;
		this->AD = diamondtrap.AD;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap named " << this->_name << " destructor called!" << std::endl;	
}

void	DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << ", and my ClapTrap is " << this->ClapTrap::_name << std::endl;
}
