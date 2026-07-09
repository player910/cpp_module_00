#include "Phonebook.hpp"

PhoneBook::PhoneBook()
	: _contacts(), _count(0)
{

}

void PhoneBook::addNewContact()
{
	Contact newContact;
	std::string str;
	std::cout << "First Name: ";
	getline(std::cin, str);
	newContact.setFirstName(str);
	std::cout << "Last Name: ";
	getline(std::cin, str);
	newContact.setLastName(str);
	
}

void PhoneBook::searchContact()
{

}

void PhoneBook::exitProgram()
{

}