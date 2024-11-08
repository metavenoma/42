/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Span.hpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-14                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#pragma once

#include <cstdlib>
#include <vector>
#include <iostream>

#define RESET		"\033[0m"
#define CLEAR		"\033[2J\033[1;1H"
#define PINK		"\033[38;2;255;182;193m"
#define BLUE		"\033[38;5;111m"
#define GREEN		"\033[38;5;120m"
#define YELLOW		"\033[38;5;227m"
#define ORANGE		"\033[38;5;208m"
#define HOT_PINK	"\033[38;5;198m"
#define CARAMEL		"\033[38;5;180m"
#define RED		"\033[38;5;124m"
#define DARK_YELLOW	"\033[38;5;136m"

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_vector;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &span);

		~Span(void);

		Span &operator=(const Span &span);

		void		addNumber(int	number);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void		fill(unsigned int amount);
		void		printVector(void);

		class	vectorFullException : public std::exception
		{
			const char *what() const throw()
			{
				return ("Error: array is full!");
			}
		};
		
		class	noPossibleSpan : public std::exception
		{
			const char *what() const throw()
			{
				return ("Error: can't return span with less than two numbers!");
			}
		};

		class	amountException : public std::exception
		{
			const char *what() const throw()
			{
				return ("Error: amount is bigger than available space in array!");
			}
		};
};
