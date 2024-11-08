/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:41:48 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:41:49 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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
