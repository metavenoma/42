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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	tax("Tax Collector", 1);
	Bureaucrat	cop("Officer Steve", 45);
	Bureaucrat	fraud("Fraudster", 6);
	Bureaucrat	president("President Lula", 1);

	AForm		*rob = new RobotomyRequestForm("Tax Collector ");
	AForm		*fee = new ShrubberyCreationForm("Monster truck");
	AForm		*pardon = new PresidentialPardonForm("Fraudster     ");

	president.executeForm(*pardon);
	president.signAForm(*pardon);
	fraud.executeForm(*pardon);
	fraud.upGrade();
	fraud.executeForm(*pardon);
	president.executeForm(*pardon);

	cop.executeForm(*rob);
	president.signAForm(*rob);
	cop.executeForm(*rob);
	cop.executeForm(*rob);
	cop.executeForm(*rob);
	cop.executeForm(*rob);

	cop.executeForm(*fee);
	tax.signAForm(*fee);
	cop.executeForm(*fee);
	std::cout << *fee << std::endl;

	std::ifstream inputFile("Monster truck_shrubbery");
	if (inputFile.is_open())
	{
		std::string line;
		while (getline(inputFile, line))
		{
			std::cout << line << std::endl;
		}
		inputFile.close();
	}
	else
		std::cerr << "Error opening file!" << std::endl;
	delete rob;
	delete fee;
	delete pardon;
	return (0);
}
