#include "Data.hpp"

Data::Data(void): _str{"Se tem uma coisa....", "   .....que me deixa passada", "       eh gritar comigo...", "     sem eu ter feito nada.................."}, _i(420420), _b("true") {}

Data::Data(const Data &data): _i(data._i), _b(data._b) 
{
	for (int i = 0; i < 4; i++)
		_str[i] = data._str[i];
}

Data::Data(const std::string str[4], int i, bool b): _i(i), _b(b) 
{
	for (int index = 0; index < 4; index++)
		_str[index] = str[index];
}

Data &Data::operator=(const Data &data)
{
	if (this != &data)
	{
		for (int i = 0; i < 4; i++)
			_str[i] = data._str[i];
		_i = data._i;
		_b = data._b;
	}
	return (*this);
}

Data::~Data(void) {}

std::string	Data::getString(int i)
{
	return (_str[i]);
}

int		Data::getInt(void)
{
	return (this->_i);
}

bool	Data::getBool(void)
{
	return (this->_b);
}

void	Data::AsciiArt::printSpaces(int count)
{
	for (int i = 0; i < count; i++)
		std::cout << " ";
}

void	Data::AsciiArt::printBorder(int width, const char *color)
{
	for (int i = 0; i < width /  14; i++)
		std::cout << color << "【☆ 】★ 【☆ 】";
	std::cout << std::endl;
}

void	Data::AsciiArt::printWithBorder(const char * text, int width, const char *borderColor, const char *textColor)
{
	int borderWidth = (width - strlen(text) - 12) / 2;

	std::cout << CLEAR;
	printBorder(width, borderColor);
	for (int i = 0; i < 7; i++)
	{
		std::cout << "【☆ 】";
		printSpaces(width - 12);
		std::cout << "【☆ 】" << std::endl;
	}
	std::cout << "【☆ 】";
	printSpaces(borderWidth);
	std::cout << textColor << text;
	printSpaces(borderWidth);
	std::cout << borderColor << "【☆ 】" << std::endl;

	for (int i = 0; i < 7; i++)
	{
		std::cout << "【☆ 】";
		printSpaces(width - 12);
		std::cout << "【☆ 】" << std::endl;
	}
	printBorder(width, borderColor);
	std::cout << RESET;
}
