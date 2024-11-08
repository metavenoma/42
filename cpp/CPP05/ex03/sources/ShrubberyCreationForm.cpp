/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          ShrubberyCreationForm.cpp                     ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-02                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", SC_SIGN, SC_EXEC), _target("No name") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", SC_SIGN, SC_EXEC), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scform): AForm("ShrubberyCreationForm", SC_SIGN, SC_EXEC), _target(scform._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scform)
{
	AForm::operator=(scform);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void	ShrubberyCreationForm::ExecuteForm(void) const
{
	std::ofstream outputFile((_target + "_shrubbery").c_str());	
	if (outputFile.is_open())
	{
		outputFile << "\n\
                    ,@@@@@@@,\n\
            ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
         ,&%&&%&&%,@@@@@/@@@@@@,8888&88/8o\n\
        ,%&&%&&%&&%,@@@&@@@/@@@88&88888/88'\n\
        %&&%&%&/%&&%@@&@@/ /@@@88888&88888'\n\
        %&&%/ %&&%&&@@& V /@@' `88&8 `/88'\n\
        `&%& ` /%&'    |.|        & '|8'\n\
            |o|        | |         | |\n\
            |.|        | |         | |\n\
         &&/ ._&//_/__/  ,&_______/.  &_//__/_\n\
\n\
     ccee88oo                     &&& &&  & &&\n\
  C8O8O8Q8PoOb o8oo           && &&/&&|& ()|/ @, &&\n\
 dOB69QO8PdUOpugoO9bD         &&/(/&/&||/& /_/)_&/_&\n\
CgggbU8OU qOp qOdoUOdcb    &() &&/&|()|/&&/ '% & ()\n\
    6OuU  /p u gcoUodpP   &_&_&&_& |& |&&/&__%_/_& &&\n\
      &&&//  /douUP     &&   && & &| &| /& & % ()& /&&\n\
        &&&////          ()&_---()&&&&|&&-&&--%---()~\n\
         |||/&               &&     &|||\n\
         |||&/                       |||\n\
         |||||                       |||\n\
   .....//||||&....            , -=-~  .-^- _\n" << _target + "_shrubbery" << std::endl;
		outputFile.close();
	}
	else
		std::cerr << "Error opening file " << _target + "_shrubbery" << std::endl;
}
