/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:58:51 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/22 11:58:52 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int	i;
	int	size = 10;
	Zombie	*horde = zombieHorde(size, "Eldritch");

	for (i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}
