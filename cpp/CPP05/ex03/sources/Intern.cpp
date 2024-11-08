/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Intern.cpp                                    ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-02                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &intern)
{
	(void)intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

Intern::~Intern(void) {}

AForm	*Intern::createShrubbery(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomy(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidential(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string	formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*createForm[3])(const std::string &) const = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};

	int i = 0;
	while (i < 3 && formName.compare(formList[i]))
		i++;
	if (i >= 3)
	{
		std::cout << formName << " is not a valid form!" << std::endl;
		return (NULL);
	}
	return ((this->*createForm[i])(target));
}
