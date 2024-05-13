/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:47:14 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:47:15 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.h"
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &animal);
		Animal &operator=(const Animal &animal);

		virtual ~Animal();

		virtual void makeSound(void) const;
		std::string getType(void) const;
};
