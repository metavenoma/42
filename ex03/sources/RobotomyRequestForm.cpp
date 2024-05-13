/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          RobotomyRequestForm.cpp                       ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-02                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", RR_SIGN, RR_EXEC), _target("No name") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", RR_SIGN, RR_EXEC), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrform): AForm("RobotomyRequestForm", RR_SIGN, RR_EXEC), _target(rrform._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrform)
{
	AForm::operator=(rrform);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return(_target);
}

void	RobotomyRequestForm::ExecuteForm(void) const
{
//	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "*** LOUD DRILLING NOISES ***\nbzbbzbbzzzzzzzzzzzzzzzz\n...\n...\n..." <<std::endl;
	std::cout << ORANGE << (rand() % 2 == 0 ? _target + " has been robotomized successfully!" : "We failed robotomizing " + _target) << RESET << std::endl;
}
