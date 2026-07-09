#include "Contact.hpp"

Contact::Contact()
	: _firstName(""), 
	_lastName(""), 
	_nickName(""), 
	_phoneNumber(""),
	 _darkestSecret("")
{
	
}

std::string Contact::getFirstName() const
{
	return (_firstName);
}

std::string Contact::getLastName() const
{
	return (_lastName);
}

std::string Contact::getNickName() const
{
	return (_nickName);
}

std::string Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

void Contact::setFirstName(std::string newFirstName)
{
	_firstName = newFirstName;
}

void Contact::setLastName(std::string newLastName)
{
	_lastName = newLastName;
}

void Contact::setNickName(std::string newNickName)
{
	_nickName = newNickName;
}

void Contact::setPhoneNumber(std::string newPhoneNumber)
{
	_phoneNumber = newPhoneNumber;
}

void Contact::setDarkestSecret(std::string newDarkestSecret)
{
	_darkestSecret = newDarkestSecret;
}