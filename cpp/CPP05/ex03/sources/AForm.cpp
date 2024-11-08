/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          AForm.cpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-01                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "AForm.hpp"


AForm::AForm(void): _name("No name"), _signed(false), _signGrade(MIN_G), _execGrade(MIN_G) {}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX_G)
		throw AForm::GradeTooHighException();
	if (signGrade > MIN_G)
		throw AForm::GradeTooLowException();
	if (execGrade < MAX_G)
		throw AForm::GradeTooHighException();
	if (execGrade > MIN_G)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &aform): _name(aform._name), _signed(aform._signed), _signGrade(aform._signGrade), _execGrade(aform._execGrade) {}

AForm &AForm::operator=(const AForm &aform)
{
	_signed = aform._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &aform)
{
	os << "★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★" << std::endl;
	os << "★ ★ ★ ★ ★ Name: " << aform.getName() << " ★ ★ ★ ★ ★ ★" << std::endl;
	os << "★ ★ ★ ★ ★ ★ ★ Signed status: " << (aform.getStatus() ? "true" : "false") << " ★ ★ ★ ★ ★ ★ ★ ★" << std::endl;
	os << "★ ★ ★ ★ ★ Min grade needed to sign: " << aform.getSignGrade() << " ★ ★ ★ ★ ★" << std::endl;
	os << "★ ★ ★ ★ ★ Min grade needed to exec: " << aform.getExecGrade() << " ★ ★ ★ ★ ★ " << std::endl;
	os << "★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★" << std::endl;
	return (os);
}

AForm::~AForm(void) {}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getStatus(void) const
{
	return (_signed);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (_execGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	if (AForm::getStatus() == true)
		throw AForm::SignedException();
	_signed = true;
}

void	AForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();
	if (_signed == false)
		throw AForm::NotSignedException();
	ExecuteForm();
}
