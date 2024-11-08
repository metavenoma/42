/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:01 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:02 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat &cat);
		Cat &operator=(const Cat &cat);

		virtual ~Cat();

		virtual void	makeSound(void) const;
		Brain& getBrain(void) const;
};
