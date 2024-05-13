/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Harl.cpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "../includes/Harl.hpp"

Harl::Harl(void)
{
	this->level[0] = std::make_pair("DEBUG", &Harl::debug);
	this->level[1] = std::make_pair("INFO", &Harl::info);
	this->level[2] = std::make_pair("WARNING", &Harl::warning);
	this->level[3] = std::make_pair("ERROR", &Harl::error);
	return;
}

Harl::~Harl(void)
{
	return;
}

void	Harl::debug(void)
{
	std::cout << "\nI hate when cis people\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "\nNo competitions! I refuse to compete with ugly people!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "\nI hate when people stare at me as if I wasn't dangerous. If you're not afraid of trans people, you should!\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "\nI don't really know how to complain, it messes with my beauty\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->level[i].first)
		{
			(this->*(this->level[i].second))();
			return;
		}
	}
}
