/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Floor.cpp                                     ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-04-30                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Floor.hpp"

Floor::Floor(void)
{
	std::cout << "Floor default constructor called!" << std::endl;
	head = NULL;
}

Floor::Floor(const Floor &floor)
{
	std::cout << "Floor copy constructor called!" << std::endl;
	head = new MateriaNode(*floor.head);
}

Floor &Floor::operator=(const Floor &floor)
{
	std::cout << "Floor copy assignment constructor called!" << std::endl;
	if (this != &floor)
		head = new MateriaNode(*floor.head);
	return (*this);
}

Floor::~Floor(void)
{
	deleteNodes();
}

void	Floor::addNode(AMateria *materia)
{
	MateriaNode *newNode = new MateriaNode(materia);
	if (!head)
		head = newNode;
	else
	{
		MateriaNode *current = head;
		while (current->getNext())
			current = current->getNext();
		current->setNext(newNode);
	}
}

void	Floor::deleteNodes(void)
{
	MateriaNode *current = head;
	while (current)
	{
		MateriaNode *temp = current;
		current = current->getNext();
		delete temp->getMateria();
		delete temp;
	}
	head = NULL;
}
