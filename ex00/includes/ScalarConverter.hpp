/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          ScalarConverter.hpp                           ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-02                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>

#include <climits>
#include <cfloat>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define INVALID 5
#define PRINT 6
#define N_DISPLAY 7
#define OVERFLOW 8
#define UNDERFLOW 9
#define IMPOSSIBLE 10
#define M_INF 11
#define P_INF 12
#define NAN 13

class ScalarConverter
{
	private:
			char	_char;
			int		_int;
			float	_float;
			double	_double;
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &sc);
		ScalarConverter &operator=(const ScalarConverter &sc);

		~ScalarConverter(void);

		bool	isSpecialFloat(const std::string &literal);
		bool	isSpecialDouble(const std::string &literal);
		bool	isInt(const std::string &literal);
		bool	isFloat(const std::string &literal);
		bool	isDouble(const std::string &literal);
		bool	isChar(const std::string &literal);
		int		getType(const std::string &literal);
		int		getSpecialCase(const std::string &literal);
		int		convertChar(const std::string &literal);
		int		convertInt(const std::string &literal);
		int		convertFloat(const std::string &literal);
		int		convertDouble(const std::string &literal);
		bool	printSwitch(std::string type, int flag);
		void	convert(const std::string &literal);
};
