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
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Base.hpp"
#include <iostream>

Base	*generate(void)
{
	Base *result = NULL;

	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			result = new A();
			break ;
		case 1:
			result = new B();
			break ;
		case 2:
			result = new C();
			break ;
	}
	return (result);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Pointer is of type \"A\"" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer is of type \"B\"" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer is of type \"C\"" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference is of type \"A\"" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference is of type \"B\"" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference is of type \"C\"" << std::endl;
	}
	catch (std::exception &e) {}
}

int	main(void)
{
	Base *base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
