#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone1;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, str);
		if (str == "ADD")
			phone1.addContacts();
		if (str == "SEARCH")
			phone1.search();
		if (std::cin.eof())
		{
			printStr("");
			return (0);
		}
	}
	return (0);
}

