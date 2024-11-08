/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:43 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:48:44 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.h"
#include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	
	public:
		Brain(void);
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);

		~Brain(void);
};
