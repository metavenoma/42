/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:41 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:42 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.h"
#include <iostream>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal(void);
		AAnimal(const AAnimal &aanimal);
		AAnimal &operator=(const AAnimal &aanimal);

		virtual ~AAnimal();

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};
