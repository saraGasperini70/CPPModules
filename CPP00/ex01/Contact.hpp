/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:33:54 by sgasperi          #+#    #+#             */
/*   Updated: 2024/05/21 12:33:57 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNum;
		std::string _secret;
	public:
		Contact(void);
		~Contact(void);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNum(void) const;
		std::string	getSecret(void) const;
		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickName(std::string str);
		void	setPhoneNum(std::string str);
		void	setSecret(std::string str);
};

#endif
