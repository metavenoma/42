/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:50:54 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:50:56 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &ice);
		Ice &operator=(const Ice &ice);

		~Ice(void);
		AMateria	*clone(void) const;
		void	use(ICharacter &target);
};
