/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:27 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:28 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	int	size = 3;
	Animal	*animalArray[size * 2];

	for (int i = 0; i < size; i++)
	{
		animalArray[i] = new Dog();
		animalArray[i + size] = new Cat();
	}
	for (int i = 0; i < size * 2; i++)
	{
		std::cout << GREEN << "Animal[" << i << "] is a " << animalArray[i]->getType() << std::endl;
		animalArray[i]->makeSound();
		if (i < size)
		{
			Dog* dogPtr = static_cast<Dog*>(animalArray[i]);
			std::cout << ORANGE << "Brain address from Animal[" << i << "] = " << &dogPtr->getBrain() << std::endl;
		}
		else
		{
			Cat* catPtr = static_cast<Cat*>(animalArray[i]);
			std::cout << ORANGE << "Brain address from Animal[" << i << "] = " << &catPtr->getBrain() << std::endl;
		}
	}

	for (int i = 0; i < size * 2; i++)
		delete animalArray[i];

	return (0);
}
