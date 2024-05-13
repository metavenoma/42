/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          main.cpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-01                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	low("Low", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Created with lower than 150 grade: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	high("High", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Created with higher than 1 grade: " << e.what() << std::endl;
	}
	Bureaucrat tax("Tax Collector", 1);
	Bureaucrat cop("Steve", 150);
	try
	{
		tax.upGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << tax << " moved to a grade too high: " << e.what() << std::endl;
	}
	try
	{
		cop.downGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << cop << " moved to a grade too low: " << e.what() << std::endl;
	}
	return (0);
}
