/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:00:35 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/22 14:50:06 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl created." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destroyed." << std:: endl;
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void Harl::complain( std::string level )
{
	// void	(Harl::*functionsPTRS[])( void ) = {&Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
	std::string	levels[] = {"INFO", "DEBUG", "WARNING", "ERROR"};
	int	i = 0;

	for (i = 0; i < 5; i++)
	{
		if (level == levels[i])
			break ;
	}

	switch (i)
	{
		case 0:
			this->debug();
			this->info();
			this->warning();
			this->error();
			break ;
		case 1:
			this->info();
			this->warning();
			this->error();
			break ;
		case 2:
			this->warning();
			this->error();
			break ;
		case 3:
			this->error();
			break ;
		default:
			std::cout << "Error: invalid input." << std::endl;
			break ;
	}
}
