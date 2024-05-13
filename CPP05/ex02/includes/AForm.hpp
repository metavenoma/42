/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          AForm.hpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-01                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#pragma once

#include <Bureaucrat.hpp>

#define MIN_G 150
#define MAX_G 1

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool			_signed;
		int const		_signGrade;
		int const		_execGrade;
	protected:
		virtual void	ExecuteForm(void) const = 0;
	public:
		AForm(void);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &aform);
		AForm &operator=(const AForm &aform);
		
		virtual ~AForm(void);


		std::string	getName(void) const;
		bool	getStatus(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		void	beSigned(const Bureaucrat &bureaucrat);
		void	execute(const Bureaucrat &bureaucrat) const;
		
		class	SignedException : public std::exception
		{
			const char* what() const throw()
			{
				return ("it is already signed!");
			}
		};
		class	NotSignedException : public std::exception
		{
			const char* what() const throw()
			{
				return ("it is not signed!");
			}
		};
		class	GradeTooLowException : public std::exception
		{
			const char* what() const throw()
			{
				return ("grade is too low!");
			}
		};
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw()
			{
				return ("grade is too high!");
			}
		};
};
std::ostream &operator<<(std::ostream &os, const AForm &aform);
