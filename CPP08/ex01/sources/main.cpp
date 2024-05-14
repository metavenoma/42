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
/*   Date: 2024-05-14                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Span.hpp"

int	main(void)
{
	Span	*span = new Span(5);
	std::cout
		<< PINK
		<< "\n▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰"
		<< RESET << std::endl;

	std::cout 
		<< YELLOW << "\n[TEST 1]\n"
		<< "Trying to fill array with more numbers than allowed:\n" 
		<< RESET << std::endl;
	try
	{
		span->fill(10001);
	}
	catch (std::exception &e)
	{
		std::cout << ORANGE << e.what() << std::endl << RESET;
	}
	
	std::cout
		<< PINK
		<< "\n▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀"
		<< RESET << std::endl;

	std::cout
		<< BLUE << "\n[TEST 2]\n"
		<< "Trying to get a span with empty array:\n"
		<< RESET << std::endl;

	try
	{
		int i = span->shortestSpan();
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << ORANGE << e.what() << std::endl << RESET;
	}

	std::cout 
		<< PINK
		<< "\n━━━━━━━ʕ•㉨•ʔ━━━━━━ʕ•㉨•ʔ━━━━━━ʕ•㉨•ʔ━━━━━━ʕ•㉨•ʔ━━━━━━━" 
		<< RESET << std::endl;

	std::cout
		<< YELLOW << "\n[TEST 3]\n"
		<< "Intra pdf test:\n"
		<< RESET << std::endl;
	span->addNumber(6);
	span->addNumber(3);
	span->addNumber(17);
	span->addNumber(9);
	span->addNumber(11);

	std::cout << span->shortestSpan() << std::endl;
	std::cout << span->longestSpan() << std::endl;

	std::cout 
		<< PINK
		<< "\n˚₊ ˚ ꙳ ੭ * ‧ ⨯ . ⁺ ✦ ‧ ⨯ (๑>ᴗ<๑) . ⁺ ✦ * . ˚ ⨯ ੭ * ‧₊ *˚" 
		<< RESET << std::endl;

	std::cout 
		<< BLUE << "\n[TEST 4]\n"
		<< "Trying to get more numbers in an array that is full\n"
		<< RESET << std::endl;
	try
	{
		span->addNumber(7);
	}
	catch (std::exception &e)
	{
		std::cout << ORANGE << e.what() << RESET << std::endl;
	}
	delete (span);

	std::cout 
		<< PINK
		<< "\n(･ω･)つ ───────────────────────────────────────── ⊂(･ω･)" 
		<< RESET << std::endl;

	span = new Span(20000);
	std::cout
		<< YELLOW << "\n[TEST 5]\n"
		<< "Filling the array with function \"fill\":\n"
		<< RESET << std::endl;
	span->fill(100);
	span->printVector();

	std::cout
		<< PINK
		<< "\n︻デ═一・・・・・・・・・・・・・・・・・・・・・・・・・"
		<< RESET << std::endl;
	std::cout 
		<< BLUE << "\n[TEST 6]\n"
		<< "Getting shortest span between elements in array:\n"
		<< RESET << std::endl;
	std::cout << span->shortestSpan() << std::endl;

	std::cout
		<< PINK
		<< "\n─ ⋆⋅☆⋅⋆ ───── ⋆⋅☆⋅⋆ ───── ⋆⋅☆⋅⋆ ───── ⋆⋅☆⋅⋆ ───── ⋆⋅☆⋅⋆ ─"
		<< RESET << std::endl;
	std::cout
		<< YELLOW << "\n[TEST 7]\n"
		<< "Getting largest span between elements in array:\n"
		<< RESET << std::endl;
	std::cout << span->longestSpan() << std::endl;

	std::cout
		<< PINK
		<< "\n▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰"
		<< RESET << std::endl;
	delete (span);
	return (0);
}
