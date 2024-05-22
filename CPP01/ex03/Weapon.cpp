/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:59:45 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/22 11:59:46 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon " << this->_type << " created." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << this->_type << " destroyed." << std::endl;
}

const std::string	&Weapon::getType(void)
{
	return this->_type;
}


void	Weapon::setType(std::string type)
{
	this->_type = type;
}

