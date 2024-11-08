/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:41:45 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:41:46 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
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
