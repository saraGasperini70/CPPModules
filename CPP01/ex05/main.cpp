/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:00:23 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/22 12:00:24 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl harl;

	std::cout << "Testing harl's debug..." << std::endl;
	harl.complain("DEBUG");
	std::cout << "Testing harl's info..." << std::endl;
	harl.complain("INFO");
	std::cout << "Testing harl's warning..." << std::endl;
	harl.complain("WARNING");
	std::cout << "Testing harl's error..." << std::endl;
	harl.complain("ERROR");
}
