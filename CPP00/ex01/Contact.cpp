#include "PhoneBook.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

//Getters
std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string	Contact::getNickName(void) const
{
	return (this->_nickName);
}
std::string	Contact::getPhoneNum(void) const
{
	return (this->_phoneNum);
}

std::string	Contact::getSecret(void) const
{
	return (this->_secret);
}

//Setters
void	Contact::setFirstName(std::string str)
{
	this->_firstName = str;
}

void	Contact::setLastName(std::string str)
{
	this->_lastName = str;
}

void	Contact::setNickName(std::string str)
{
	this->_nickName = str;
}

void	Contact::setPhoneNum(std::string str)
{
	this->_phoneNum = str;
}

void	Contact::setSecret(std::string str)
{
	this->_secret = str;
}


