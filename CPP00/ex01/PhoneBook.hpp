/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:18 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/21 13:02:40 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include "utils.hpp"
# include <iomanip>

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
