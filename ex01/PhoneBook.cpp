/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksahinoz <ksahinoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:21:47 by ksahinoz          #+#    #+#             */
/*   Updated: 2026/07/21 14:47:46 by ksahinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>
#include <cctype>

PhoneBook::PhoneBook()
	: _contacts(), _totalCount(0)
{

}

bool PhoneBook::addNewContact()
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
			if (std::cin.eof())
			{
				std::cout << "EOF detected, exiting..." << std::endl;
				return (false);
			}
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
			if (std::cin.eof())
			{
				std::cout << "EOF detected, exiting..." << std::endl;
				return (false);
			}
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
			if (std::cin.eof())
			{
				std::cout << "EOF detected, exiting..." << std::endl;
				return (false);
			}
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
			if (std::cin.eof())
			{
				std::cout << "EOF detected, exiting..." << std::endl;
				return (false);
			}
			if (str.empty())
			{
				std::cout << "Phone Number can't be empty" << std::endl;
				continue;
			}
			if (!isWholeNum(str))
			{
				std::cout << "Phone Number isn't valid" << std::endl;
				continue;
			}
			newContact.setPhoneNumber(str);
			finder++;
		}
		if (finder == 4)
		{
			std::cout << "Darkest Secret: ";
			getline(std::cin, str);
			if (std::cin.eof())
			{
				std::cout << "EOF detected, exiting..." << std::endl;
				return (false);
			}
			if (str.empty())
			{
				std::cout << "Darkest Secret can't be empty" << std::endl;
				continue;
			}
			newContact.setDarkestSecret(str);
		}
		_contacts[_totalCount % 8] = newContact;
		_totalCount++;
		std::cout << "New contact added" << std::endl;
		break ;
	}
	return (true);
}

bool PhoneBook::searchContact()
{
	if (!_totalCount)
	{
		std::cout << "Empty Phonebook" << std::endl;
		return (true);
	}
	std::cout << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST NAME" << "|" <<
		std::setw(10) << "LAST NAME" << "|" << std::setw(10) << "NICKNAME" << std::endl;

	int i = 0;
	int border;
	if (_totalCount > 8)
		border = 8;
	else
		border = _totalCount;
	while(i < border)
	{
		std::cout << std::setw(10) << i << "|" <<
					 std::setw(10) << truncateString(_contacts[i].getFirstName()) << "|" <<
					 std::setw(10) << truncateString(_contacts[i].getLastName()) << "|" <<
					 std::setw(10) << truncateString(_contacts[i].getNickName()) <<
					 std::endl;
		i++;
	}
	std::cout << "Enter index: ";
	std::string str;
	getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << "EOF detected, exiting..." << std::endl;
		return (false);
	}
	if (str.empty())
	{
		std::cout << "Index input can't be empty" << std::endl;
		return (true);
	}
	if (!isWholeNum(str))
	{
		std::cout << "Index input invalid" << std::endl;
		return (true);
	}
	int index;
	std::stringstream ss;
	ss << str;
	ss >> index;
	if (index >= border)
	{
		std::cout << "Index input invalid" << std::endl;
		return (true);
	}
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl <<
				 "Last name: " << _contacts[index].getLastName() << std::endl <<
				 "Nickname: " << _contacts[index].getNickName() << std::endl <<
				 "Phone number: " << _contacts[index].getPhoneNumber() << std::endl <<
				 "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
	return (true);				
}

void PhoneBook::exitProgram()
{
	std::cout << "Exitting the program..." << std::endl;
}

bool PhoneBook::isWholeNum(std::string newNum)
{
	size_t i = 0;
	while(i < newNum.length())
	{
		if (!std::isdigit(newNum[i]))
			return (false);
		i++;
	}
	return (true);
}

std::string PhoneBook::truncateString(std::string str) const
{
	size_t len = str.length();
	if (len > 10)
	{
		std::string trunStr;
		size_t i = 0;
		while (i < 9)
		{
			trunStr += str[i];
			i++;
		}
		trunStr += '.';
		return (trunStr);
	}
	else
		return (str);
}
