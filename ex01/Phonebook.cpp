#include "Phonebook.hpp"

PhoneBook::PhoneBook()
	: _contacts(), _count(0), _current_user(0)
{

}

void PhoneBook::addNewContact()
{
	Contact newContact;
	std::string str;
	int finder = 0;
	while(1)
	{
		if (finder == 0)
		{
			std::cout << "First Name: ";
			getline(std::cin, str);
			if (str.empty())
			{
				std::cout << "First Name can't be empty" << std::endl;
				continue;
			}

			newContact.setFirstName(str);
			finder++;
		}
		if (finder == 1)
		{
			std::cout << "Last Name: ";
			getline(std::cin, str);
			if (str.empty())
			{
				std::cout << "Last Name can't be empty" << std::endl;
				continue;
			}
			newContact.setLastName(str);
			finder++;
		}
		if (finder == 2)
		{
			std::cout << "Nickname: ";
			getline(std::cin, str);
			if (str.empty())
			{
				std::cout << "Nickname can't be empty" << std::endl;
				continue;
			}
			newContact.setNickName(str);
			finder++;
		}
		if (finder == 3)
		{
			std::cout << "Phone Number: ";
			getline(std::cin, str);
			if (str.empty())
			{
				std::cout << "Phone Number can't be empty" << std::endl;
				continue;
			}
			if (!isWholeNum(str))
				continue;
			newContact.setPhoneNumber(str);
			finder++;
		}
		if (finder == 4)
		{
			std::cout << "Darkest Secret: ";
			getline(std::cin, str);
			if (str.empty())
			{
				std::cout << "Darkest Secret can't be empty" << std::endl;
				continue;
			}
			newContact.setDarkestSecret(str);
		}
		_contacts[_count] = newContact;
		_count++;
		if (_count == 8)
			_count = 0;
		std::cout << "New contact added" << std::endl;
		break ;
	}
}

void PhoneBook::searchContact()
{

}

void PhoneBook::exitProgram()
{

}

bool PhoneBook::isWholeNum(std::string newNum)
{
	size_t i = 0;
	while(i < newNum.length())
	{
		if (newNum[i] < '0' || newNum[i] > '9')
		{
			std::cout << "Phone Number isn't valid" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}
