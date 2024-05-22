/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:59:05 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/22 11:59:06 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int	i;
	Zombie	*horde = new Zombie[N];

	for (i=0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
