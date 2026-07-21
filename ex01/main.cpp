/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksahinoz <ksahinoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:21:38 by ksahinoz          #+#    #+#             */
/*   Updated: 2026/07/21 14:47:57 by ksahinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;

	std::string in;
	while (1)
	{
		std::cout << "Write a command: ";
		getline(std::cin, in);
		if (std::cin.eof())
		{
			std::cout << "EOF detected, exiting..." << std::endl;
			return (1);
		}
		if (in == "ADD")
		{
			if (!phonebook.addNewContact())
				return (1);
		}
		else if (in == "SEARCH")
		{
			if (!phonebook.searchContact())
				return (1);
		}
		else if (in == "EXIT")
		{
			phonebook.exitProgram();
			break;
		}
	}
	return (0);
}
