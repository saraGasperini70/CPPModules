/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:59:21 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/22 11:59:22 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon	&_weapon;
		std::string	_name;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack(void);
		void	setWeapon(Weapon weapon);
};
#endif
