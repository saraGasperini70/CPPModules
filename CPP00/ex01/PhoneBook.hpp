#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include "utils.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContacts(void);
		void	printContacts(Contact contact);
		void	search(void);
		Contact	getContact(int index);
};

#endif
