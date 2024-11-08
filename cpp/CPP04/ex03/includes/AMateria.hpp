/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:50:41 by rverona-          #+#    #+#             */
/*   Updated: 2024/04/30 09:50:42 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ICharacter.hpp>

class ICharacter;

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(void);
		AMateria(std::string const &tp);
		AMateria(const AMateria &amateria);
		AMateria &operator=(const AMateria &amateria);

		virtual ~AMateria(void) = 0;

		std::string const	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};
