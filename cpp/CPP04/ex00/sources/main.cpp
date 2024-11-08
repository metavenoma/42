/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:47:40 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:47:41 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *animal = new Animal();
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();
	const WrongAnimal *wanimal = new WrongAnimal();
	const WrongAnimal *wcat = new WrongCat();
	const WrongCat wcat2;

	std::cout << 
		"Anymal type: " << animal->getType() << "\n" \
		<< "Cat type: " << cat->getType() << "\n" \
		<< "Dog type: " << dog->getType() << "\n" \
		<< "Wrong animal type: " << wanimal->getType() << "\n" \
		<< "Wrong cat type: " << wcat->getType() << std::endl;
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
	wanimal->makeSound();
	wcat->makeSound();
	wcat2.makeSound();

	delete animal;
	delete cat;
	delete dog;
	delete wanimal;
	delete wcat;

	return (0);
}
