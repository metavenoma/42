/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Span.cpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-14                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Span.hpp"

Span::Span(void) : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &span) : _maxSize(span._maxSize), _vector(span._vector) {}

Span::~Span(void) {}

Span	&Span::operator=(const Span &span)
{
	if (this != &span)
	{
		this->_maxSize = span._maxSize;
		this->_vector = span._vector;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_vector.size() == _maxSize)
		throw (Span::vectorFullException());
	_vector.push_back(number);
}

unsigned int	Span::shortestSpan(void)
{
	if (_vector.size() < 2)
		throw (Span::noPossibleSpan());
	unsigned int	span = std::abs(_vector[1] - _vector[0]);
	for (size_t i = 2; i < _vector.size(); i++)
	{
		if (static_cast<unsigned int>(std::abs(_vector[i] 
			- _vector[i - 1])) < span)
			span = std::abs(_vector[i] - _vector[i - 1]);
	}
	return (span);
}

unsigned int	Span::longestSpan(void)
{
	if (_vector.size() < 2)
		throw (Span::noPossibleSpan());
	unsigned int	span = std::abs(_vector[1] - _vector[0]);
	for (size_t i = 2; i < _vector.size(); i++)
	{
		if (static_cast<unsigned int>(std::abs(_vector[i]
			- _vector[i - 1])) > span)
			span = std::abs(_vector[i] - _vector[i - 1]);
	}
	return (span);
}

void	Span::fill(unsigned int amount)
{
	if (static_cast<unsigned long>(this->_vector.size() \
		+ static_cast<unsigned long>(amount) \
		> static_cast<unsigned long>(this->_maxSize)))
		throw (Span::amountException());
	srand(time(NULL));
	for (unsigned int i = 0; i < amount; i++)
		this->_vector.push_back(rand());
}

void	Span::printVector(void)
{
	if (_vector.size() > 0)
	{
		unsigned long i = 0;
		while (i < _vector.size() - 1)
		{
			std::cout << _vector[i] << ",";
			i++;
		}
		std::cout << _vector[i] << std::endl;
	}
}

