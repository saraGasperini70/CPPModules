/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:33:20 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/21 12:33:23 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	size_t	i;
	size_t	j;

	if (ac >= 2)
	{
		for (i = 1; av[i] != NULL; i++)
		{
			std::string str = av[i];
			for (j = 0; j < str.length(); j++)
				std::cout << (char) toupper(str[j]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
