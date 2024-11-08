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
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form	low("Low", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Created with lower than 150 exec grade: " << e.what() << std::endl;
	}
	try
	{
		Form	high("High", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Created with higher than 1 exec grade: " << e.what() << std::endl;
	}
	try
	{
		Form	lows("Lows", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Created with lower than 150 sign grade: " << e.what() << std::endl;
	}
	try
	{
		Form	highs("Highs", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Created with higher than 1 exec grade: " << e.what() << std::endl;
	}

	Bureaucrat	tax("Tax Collector", 1);
	Bureaucrat	cop("Steve", 150);
	Bureaucrat	fraud("Fraudster", 20);
	Form		taxes("Taxes ★ ★ ★", 30, 30);
	Form		fee("Parking fee", 10, 10);
	std::cout << "\n" << tax << " tried to sign \n" << std::endl << taxes << std::endl;
	tax.signForm(taxes);
	std::cout << "Result: \n" << taxes << std::endl;
	std::cout << "\n" << cop << " tried to sign \n" << std::endl << fee << std::endl;
	cop.signForm(fee);
	std::cout << "Result: \n" << fee << std::endl;
	std::cout << "\n" << fraud << " tried to sign \n" << std::endl << taxes << std::endl;
	fraud.signForm(taxes);
	std::cout << "Result: \n" << taxes << std::endl;
	return (0);
}
