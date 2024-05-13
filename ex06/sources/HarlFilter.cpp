/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          HarlFilter.cpp                                ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "../includes/HarlFilter.hpp"

HarlFilter::HarlFilter(void)
{
	this->level[0] = std::make_pair("DEBUG", &HarlFilter::debug);
	this->level[1] = std::make_pair("INFO", &HarlFilter::info);
	this->level[2] = std::make_pair("WARNING", &HarlFilter::warning);
	this->level[3] = std::make_pair("ERROR", &HarlFilter::error);
	return;
}

void	HarlFilter::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "\nI actually hate when people leave hair stuck in combs\n" << std::endl;
}

void	HarlFilter::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "\nIs just so unfair I wasn't born a billionaire\n" << std::endl;
}

void	HarlFilter::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "\nLike, for real, not even a f*ing millionaire!!!!!!\n" << std::endl;
}

void	HarlFilter::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "\nIs trully disgusting to be that pretty and broke. I'm out.\n" << std::endl;
}

void	HarlFilter::complain(std::string level)
{
	int i = 0;
	while (i < 4)
	{
		if (level == this->level[i].first)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			(this->*(this->level[i].second))();
			i++;
		case 1:
			(this->*(this->level[i].second))();
			i++;
		case 2:
			(this->*(this->level[i].second))();
			i++;
		case 3:
			(this->*(this->level[i].second))();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return ;
	}
}
