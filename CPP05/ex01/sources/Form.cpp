/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Form.cpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-01                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Form.hpp"


Form::Form(void): _name("No name"), _signed(false), _signGrade(MIN_G), _execGrade(MIN_G) {}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX_G)
		throw Form::GradeTooHighException();
	if (signGrade > MIN_G)
		throw Form::GradeTooLowException();
	if (execGrade < MAX_G)
		throw Form::GradeTooHighException();
	if (execGrade > MIN_G)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &form): _name(form._name), _signed(form._signed), _signGrade(form._signGrade), _execGrade(form._execGrade) {}

Form &Form::operator=(const Form &form)
{
	_signed = form._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★  ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★" << std::endl;
	os << "★ ★ ★ ★ ★ ★ ★  Form: " << form.getName() << " ★ ★ ★ ★ ★ ★ ★ ★" << std::endl;
	os << "★ ★ ★ ★ ★ ★ ★ Signed status: " << (form.getStatus() ? "true " : "false") << " ★ ★ ★ ★ ★ ★ ★" << std::endl;
	os << "★ ★ ★ ★ ★ Min grade needed to sign: " << form.getSignGrade() << " ★ ★ ★ ★ ★" << std::endl;
	os << "★ ★ ★ ★ ★ Min grade needed to exec: " << form.getExecGrade() << " ★ ★ ★ ★ ★ " << std::endl;
	os << "★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★  ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★" << std::endl;
	return (os);
}

Form::~Form(void) {}

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getStatus(void) const
{
	return (_signed);
}

int	Form::getSignGrade(void) const
{
	return (_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (_execGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	if (Form::getStatus() == true)
		throw Form::SignedException();
	_signed = true;
}
