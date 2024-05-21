/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:27 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/21 13:07:33 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	printStr(std::string str)
{
	std::cout << str << std::endl;
}

std::string	fix_width(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	search_ui(Contact contacts[8])
{
	char	c;
	int		i;
	std::string str;

	printStr(" ___________________________________________ ");
	printStr("|     Index|First Name| Last Name|  Nickname|");
	printStr(" ___________________________________________ ");
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].getFirstName().size() && ++i)
		{
			str = c;
			str = fix_width(str, 10);
			std::cout << "|" << std::setw(10) << str;
			str = fix_width(contacts[c - 1 - '0'].getFirstName(), 10);
			std::cout << "|" << std::setw(10) << str;
			str = fix_width(contacts[c - 1 - '0'].getLastName(), 10);
			std::cout << "|" << std::setw(10) << str;
			str = fix_width(contacts[c - 1 - '0'].getNickName(), 10);
			std::cout << "|" << std::setw(10) << str;
			printStr("|");
		}
	}
	printStr(" ___________________________________________ ");
	return (i);
}
