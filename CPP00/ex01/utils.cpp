#include "PhoneBook.hpp"

void	printStr(std::string str)
{
	std::cout << str << std::endl;
}

std::string	add_spaces(int n)
{
	std:: string str;

	while (n--)
		str.append(" ");
	return(str);
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
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].getFirstName(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].getLastName(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].getNickName(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			printStr("|");
		}
	}
	printStr(" ___________________________________________ ");
	return (i);
}
