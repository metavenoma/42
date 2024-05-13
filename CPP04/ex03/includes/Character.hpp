/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:50:44 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:50:45 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "Floor.hpp"
#define SLOTS 4

class Floor;

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria*	inventory[SLOTS];
		int		index;
		Floor		*floor;
	public:
		Character(void);
		Character(std::string name);
		Character(const Character &character);
		Character &operator=(const Character &character);

		~Character(void);
		const std::string	&getName(void) const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};
