#pragma once

#include <iostream>
#include <cstring>
#include "Serializer.hpp"
#include <unistd.h>

#define WIDTH		84
#define RESET		"\033[0m"
#define CLEAR		"\033[2J\033[1;1H"
#define PINK		"\033[38;2;255;182;193m"
#define BLUE		"\033[38;5;111m"
#define GREEN		"\033[38;5;120m"
#define YELLOW		"\033[38;5;227m"
#define ORANGE		"\033[38;5;208m"
#define HOT_PINK	"\033[38;5;198m"

class Data
{
	private:
			std::string	_str[4];
			int			_i;
			bool		_b;
	public:
			Data(void);
			Data(const Data &data);
			Data(const std::string str[4], int i, bool b);
			Data &operator=(const Data &data);

			~Data(void);

			std::string	getString(int i);
			int		getInt(void);
			bool	getBool(void);

			class AsciiArt
			{
				private: 
					static void	printSpaces(int count);
					static void	printBorder(int width, const char *borderColor);
				public:
					static void	printWithBorder(const char* text, int width, const char *borderColor, const char *textColor);
			};
};
