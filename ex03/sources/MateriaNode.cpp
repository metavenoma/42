/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          MateriaNode.cpp                               ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-04-30                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "MateriaNode.hpp"

MateriaNode::MateriaNode(void): materia(NULL), next(NULL)
{
	std::cout << "MateriaNode default constructor called!" << std::endl;
}

MateriaNode::MateriaNode(AMateria *m): materia(m), next(NULL)
{
	std::cout << "MateriaNode materia constructor called!" << std::endl;
}

MateriaNode::MateriaNode(const MateriaNode &materianode)
{
	std::cout << "MateriaNode copy constructor called!" << std::endl;
	this->materia = materianode.materia;
	this->next = materianode.next;
}

MateriaNode &MateriaNode::operator=(const MateriaNode &materianode)
{
	if (this != &materianode)
	{
		this->materia = materianode.materia;
		this->next = materianode.next;
	}
	return (*this);
}

MateriaNode::~MateriaNode(void)
{
	std::cout << "MateriaNode destructor called!" << std::endl;
}

AMateria	*MateriaNode::getMateria(void) const
{
	return (materia);
}

MateriaNode	*MateriaNode::getNext(void) const
{
	return (next);
}

void	MateriaNode::setNext(MateriaNode *node)
{
	next = node;
}
