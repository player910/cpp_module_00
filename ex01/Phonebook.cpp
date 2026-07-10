#include "Phonebook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
	: _contacts(), _count(0), _totalCount(0)
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
		_totalCount++;
		if (_count == 8)
			_count = 0;
		std::cout << "New contact added" << std::endl;
		break ;
	}
}

void PhoneBook::searchContact()
{
	if (!_totalCount)
	{
		std::cout << "Empty Phonebook" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "INDEX|" << std::setw(10) << "FIRST NAME|" <<
		std::setw(10) << "LAST NAME|" << std::setw(10) << "NICKNAME" << std::endl; 
	int i = 0;

	while(i < _totalCount)
	{
		int index = i % 8;
		std::cout << std::setw(10) << index <<"|" << std::setw(10) << _contacts[index].getFirstName() + "|" <<
			std::setw(10) << _contacts[index].getLastName() + "|" << _contacts[index].getNickName() << std::endl; 	
		i++;
	}

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

std::string PhoneBook::truncateString(std::string str) const
{
	if (str.length() <= 10)
		return (str);
	int i = 0;
	std::string trunStr;
	while(i < 10)
	{
		trunStr[i] = str[i];
		i++;
	}
	trunStr[i] = '.';
	return (trunStr);
}