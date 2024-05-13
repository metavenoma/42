/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          MateriaSource.cpp                             ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-04-30                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void): index(0)
{
	std::cout << "MateriaSource default constructor called!" << std::endl;
	for (int i = 0; i < MSLOTS; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiasource): index(materiasource.index)
{
	std::cout << "MateriaSource copy constructor called!" << std::endl;
	for (int i = 0; i < MSLOTS; i++)
	{
		this->materias[i] = NULL;
		if (materiasource.materias[i] != NULL)
			this->materias[i] = materiasource.materias[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiasource)
{
	std::cout << "MateriaSource copy assignment operator called!" << std::endl;
	if (this != &materiasource)
	{
		for (int i = 0; i < MSLOTS; i++)
		{
			if (this->materias[i] != NULL)
				delete this->materias[i];
			this->materias[i] = NULL;
			if (materiasource.materias[i] != NULL)
				this->materias[i] = materiasource.materias[i]->clone();
		}
		this->index = materiasource.index;
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called, memory address = " << this << std::endl;
	for (int i = 0; i < MSLOTS; i++)
	{
		if (this->materias[i] != NULL)
			delete this->materias[i];
	}
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (this->index == -1)
	{
		if (materia != NULL)
			delete materia;
		return ;
	}
	for (int i = 0; i < MSLOTS; i++)
	{
		if (this->materias[i] == materia)
			return ;
	}
	if (this->materias[this->index] == NULL)
	{
		this->materias[this->index] = materia;
		this->index = this->index + 1 >= MSLOTS ? -1 : this->index + 1;
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < MSLOTS; i++)
	{
		if (this->materias[i] != NULL)
		{
			if (this->materias[i]->getType() == type)
				return (this->materias[i]->clone());
		}
	}
	return (0);
}
