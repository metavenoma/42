/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          ScalarConverter.cpp                           ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-02                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &sc) 
{
	(void)sc;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc)
{
	(void)sc;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

bool	ScalarConverter::isSpecialFloat(const std::string &literal)
{
	std::string	specialCases[3] = {"-inff", "+inff", "nanf"};
	for (int i = 0; i < 3; i++)
	{
		if (literal == specialCases[i])
						return (true);
	}
	return (false);
}

bool	ScalarConverter::isSpecialDouble(const std::string &literal)
{
	std::string	specialCases[3] = {"-inf", "+inf", "nan"};
	for (int i = 0; i < 3; i++)
	{
		if (literal == specialCases[i])
				return (true);
	}
	return (false);
}

bool	ScalarConverter::isInt(const std::string &literal)
{
	if (literal.empty())
			return (false);
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
			i++;
	for ( ; i < literal.size(); i++)
	{
		if (!isdigit(literal[i]))
						return (false);
	}
	int num;
	try
	{
		num = std::atoi(literal.c_str());
	}
	catch (...)
	{
		return (false);
	}
	return (num >= INT_MIN && num <= INT_MAX);
}

bool	ScalarConverter::isFloat(const std::string &literal)
{
	if (isSpecialFloat(literal))
		return (true);
	bool	sign = false;
	if (literal[0] == '-' || literal[0] == '+')
			sign = true;
	if (literal.empty() || (sign && literal.length() == 1))
			return (false);
	size_t	i = sign ? 1 : 0;
	bool	hasDecimal = false;
	for ( ; i < literal.length() && literal[i] != 'f'; i++)
	{
		if (literal[i] == '.' && hasDecimal)
				return (false);
		if (!isdigit(literal[i]) && literal[i] != '.')
				return (false);
		if (literal[i] == '.')
				hasDecimal = true;
	}
	if (literal[i - 1] == '.' || literal[i] != 'f' || literal[i + 1] != '\0' || !hasDecimal)
			return (false);
	return (true);
}

bool	ScalarConverter::isDouble(const std::string &literal)
{
	if (isSpecialDouble(literal))
			return (true);
	bool	sign = false;
	if (literal[0] == '-' || literal[0] == '+')
			sign = true;
	if (literal.empty() || (sign && literal.length() == 1))
			return (false);
	size_t	i = sign ? 1 : 0;
	bool	hasDecimal = false;
	for ( ; i < literal.length(); i++)
	{
		if (literal[i] == '.' && hasDecimal)
				return (false);
		if (!isdigit(literal[i]) && literal[i] != '.')
				return (false);
		if (literal[i] == '.')
				hasDecimal = true;
	}
	if (!hasDecimal || literal[i - 1] == '.')
			return (false);
	return (true);
}

bool	ScalarConverter::isChar(const std::string &literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

int		ScalarConverter::getType(const std::string &literal)
{
		bool (ScalarConverter::*types[4])(const std::string&)  = {&ScalarConverter::isChar, &ScalarConverter::isInt, &ScalarConverter::isFloat, &ScalarConverter::isDouble};
		for (int i = 1; i < 5; i++)
		{
			if ((this->*types[i - 1])(literal) == true)
					return (i);
		}
		return (INVALID);
}

int		ScalarConverter::getSpecialCase(const std::string &literal)
{
		std::string	specialCases[6] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};
		int	i = -1;
		while (++i < 6)
		{
			if (literal == specialCases[i])
					break ;
		}
		return (i);
}

int		ScalarConverter::convertChar(const std::string &literal)
{
	switch (getType(literal))
	{
		case CHAR:
		{
			this->_char = literal[1];
			if (!isprint(this->_char))
				return  (N_DISPLAY);
			return (PRINT);
		}
		case INT:
		{
			int	i = std::atoi(literal.c_str());
			this->_char = static_cast<char>(i);
			if (i < 0)
				return (UNDERFLOW);
			if (i > std::numeric_limits<char>::max())
				return (OVERFLOW);
			if (!isprint(this->_char))
				return (N_DISPLAY);
			return (PRINT);
		}
		case FLOAT:
		{
			if (isSpecialFloat(literal))
				return (IMPOSSIBLE);
			float	f = std::atof(literal.c_str());
			if (f < 0)
				return (UNDERFLOW);
			if (f > std::numeric_limits<char>::max())
				return (OVERFLOW);
			int i = static_cast<int>(f);
			this->_char = static_cast<char>(i);
			if (!isprint(this->_char))
				return (N_DISPLAY);
			return (PRINT);
		}
		case DOUBLE:
		{
			if (isSpecialDouble(literal))
				return (IMPOSSIBLE);
			char	*endPtr;
			double	d = std::strtod(literal.c_str(), &endPtr);
			if (d < 0)
				return (UNDERFLOW);
			if (d > std::numeric_limits<char>::max())
				return (OVERFLOW);
			int i = static_cast<int>(d);
			this->_char = static_cast<char>(i);
			if (!isprint(this->_char))
				return (N_DISPLAY);
			return (PRINT);
		}
	}	
	return (INVALID);
}

int		ScalarConverter::convertInt(const std::string &literal)
{
	switch(getType(literal))
	{
		case CHAR:
		{
			this->_int = static_cast<int>(this->_char);
			return (PRINT);
		}
		case INT:
		{
			this->_int = std::atoi(literal.c_str());
			return (PRINT);
		}
		case FLOAT:
		{
			if (isSpecialFloat(literal))
				return (IMPOSSIBLE);
			float f = std::atof(literal.c_str());
			if (f < static_cast<float>(INT_MIN))
				return (UNDERFLOW);
			if (f > static_cast<float>(INT_MAX))
				return (OVERFLOW);
			this->_int = static_cast<int>(f);
			return (PRINT);
		}
		case DOUBLE:
		{
			if (isSpecialDouble(literal))
				return (IMPOSSIBLE);
			char	*endPtr;
			double d = std::strtod(literal.c_str(), &endPtr);
			if (d < INT_MIN)
				return (UNDERFLOW);
			if (d > INT_MAX)
				return (OVERFLOW);
			this->_int = static_cast<int>(d);
			return (PRINT);
		}
	}
	return (INVALID);
}

int		ScalarConverter::convertFloat(const std::string &literal)
{
	switch (getType(literal))
	{
		case CHAR:
			this->_float = static_cast<float>(this->_char);
			return (PRINT);
		case INT:
			this->_float = static_cast<float>(this->_int);
			return (PRINT);
		case FLOAT:
		{
			switch (getSpecialCase(literal))
			{
				case 3:
					return (M_INF);
				case 4:
					return (P_INF);
				case 5:
					return (NAN);
			}
			char *endPtr;
			long long ll = std::strtol(literal.c_str(), &endPtr, 10);
			if (ll <= -FLT_MAX)
					return (UNDERFLOW);
			if (ll >= FLT_MAX)
					return (OVERFLOW);
			this->_float = std::atof(literal.c_str());
			return (PRINT);
		}
		case DOUBLE:
		{
			switch(getSpecialCase(literal))
			{
				case 0:
					return (M_INF);
				case 1:
					return (P_INF);
				case 2:
					return (NAN);
			}
			char *endPtr;
			long long ll = std::strtol(literal.c_str(), &endPtr, 10);
			if (ll <= -DBL_MAX)
					return (UNDERFLOW);
			if (ll >= DBL_MAX)
					return (OVERFLOW);
			this->_float = std::atof(literal.c_str());
			return (PRINT);
		}
	}
	return (INVALID);
}

int	ScalarConverter::convertDouble(const std::string &literal)
{
	switch(getType(literal))
	{
		case CHAR:
			this->_double = static_cast<double>(this->_char);
			return (PRINT);
		case INT:
			this->_double = static_cast<double>(this->_int);
			return (PRINT);
		case FLOAT:
		{
			switch(getSpecialCase(literal))
			{
				case 6:
					break ;
				case 3:
					return (M_INF);
				case 4:
					return (P_INF);
				case 5:
					return (NAN);
			}
			char *endPtr;
			long long ll = std::strtol(literal.c_str(), &endPtr, 10);
			if (ll < -FLT_MAX)
				return (UNDERFLOW);
			if (ll > FLT_MAX)
				return (OVERFLOW);
			this->_double = std::strtod(literal.c_str(), &endPtr);
			return (PRINT);
		}
		case DOUBLE:
		{
			switch(getSpecialCase(literal))
			{
				case 6:
					break ;
				case 0:
					return (M_INF);
				case 1:
					return (P_INF);
				case 2:
					return (NAN);
			}
			char *endPtr;
			long long ll = std::strtol(literal.c_str(), &endPtr, 10);
			if (ll < -DBL_MAX)
				return (UNDERFLOW);
			if (ll > DBL_MAX)
				return (OVERFLOW);
			this->_double = std::strtod(literal.c_str(), &endPtr);
			return (PRINT);
		}
	}
	return (INVALID);
}

bool	ScalarConverter::printSwitch(std::string type, int flag)
{
	std::cout << type << ": ";
	switch (flag)
	{
			case PRINT:
				return (true);
			case N_DISPLAY:
				std::cout << "Non displayable" << std::endl;
				break;
			case OVERFLOW:
				std::cout << "Overflow" << std::endl;
				break ;
			case UNDERFLOW:
				std::cout << "Underflow" << std::endl;
				break ;
			case IMPOSSIBLE:
				std::cout << "Impossible" << std::endl;
				break ;
			case M_INF:
				std::cout << "-inf" << (type.compare("float") == 0 ? "f" : "") << std::endl;
				break ;
			case P_INF:
				std::cout << "+inf" << (type.compare("float") == 0 ? "f" : "") << std::endl;
				break ;
			case NAN:
				std::cout << "nan" << (type.compare("float") == 0 ? "f" : "") << std::endl;
				break ;
	}
	return (false);
}

void	ScalarConverter::convert(const std::string &literal)
{
	if (getType(literal) == INVALID)
	{
		std::cerr << "Can't convert: <" << literal << "> : Invalid type of literal" << std::endl;
		std::cerr << "Allowed literals are:" << std::endl;
		std::cerr << "[CHAR : <'c'>] | [INT : <0>] | [FLOAT : <0.0f>] | [DOUBLE : <0.0>]" << std::endl;
		return ;
	}
	int flag = convertChar(literal);
	if (printSwitch("char", flag) == true)
		std::cout << "\'" << this->_char << "\'" << std::endl;
	flag = convertInt(literal);
	if (printSwitch("int", flag) == true)
		std::cout << this->_int << std::endl;
	flag = convertFloat(literal);
	if (printSwitch("float", flag) == true)
		std::cout << this->_float << "f" << std::endl;
	flag = convertDouble(literal);
	if (printSwitch("double", flag) == true)
		std::cout << this->_double << std::endl;
	std::cout << std::endl;
}
