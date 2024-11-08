/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Bureaucrat.cpp                                ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-01                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name ("No name"), _grade(MIN_G) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < MAX_G)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_G)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): _name(bureaucrat._name), _grade(bureaucrat._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
		this->_grade = bureaucrat._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

void	Bureaucrat::upGrade(void)
{
	if (_grade - 1 < MAX_G)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade + 1 > MIN_G)
		throw Bureaucrat::GradeTooLowException();
	_grade--;
}

int		Bureaucrat::getGrade(void) const
{
	return (_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	return (os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " could not sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
}
