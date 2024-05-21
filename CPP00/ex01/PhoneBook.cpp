/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:08 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/21 12:34:09 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
	printStr("PhoneBook created. Max 8 contacts.");
}

PhoneBook::~PhoneBook()
{
	printStr("PhoneBook destroyed.");
}

Contact	PhoneBook::getContact(int index)
{
	return this->_contacts[index % 8];
}

void	PhoneBook::addContacts()
{
	std::string str;

	str = "";
	if (this->_index > 7)
		std::cout << "Warning: overwriting contact " << this->_contacts[this->_index % 8].getFirstName() << std::endl;
	while (!std::cin.eof() && str == "")
	{
		printStr("Insert first name:");
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setFirstName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Insert " << this->_contacts[this->_index % 8].getFirstName() << "'s last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setLastName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Insert " << this->_contacts[this->_index % 8].getFirstName() << "'s nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setNickName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Insert " << this->_contacts[this->_index % 8].getFirstName() << "'s phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setPhoneNum(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Insert " << this->_contacts[this->_index % 8].getFirstName() << "'s darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[this->_index % 8].setSecret(str);
			std::cout << _contacts[this->_index % 8].getFirstName() << " succesfully added to phonebook!" << std::endl;
		}
	}
	this->_index++;
}

void	PhoneBook::printContacts(Contact contact)
{
	if (!contact.getFirstName().size())
		printStr("Failed to get contact info");
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNum() << std::endl;
	std::cout << "Darkest secret: " << contact.getSecret() << std::endl;
}

void	PhoneBook::search(void)
{
	std::string str;

	if (!search_ui(this->_contacts))
	{
		printStr("Error: contact not found.");
		return ;
	}
	while (std::getline(std::cin, str) && str != "")
	{
		if (str.size() == 1 && (str[0] >= '1' && str[0] <= '8') && this->_contacts[str[0] - 1 - '0'].getFirstName().size())
			break ;
		if (str != "")
			printStr("Invalid index.");
	}
	if (!std::cin.eof())
		this->printContacts(this->_contacts[str[0] - 1 - '0']);
}
