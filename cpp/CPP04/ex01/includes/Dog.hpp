/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:06 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:07 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;

	public:
		Dog(void);
		Dog(const Dog &dog);
		Dog &operator=(const Dog &dog);

		virtual ~Dog(void);

		virtual void	makeSound(void) const;
		Brain&	getBrain(void) const;
};
