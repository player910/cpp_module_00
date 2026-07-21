/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksahinoz <ksahinoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:36:58 by ksahinoz          #+#    #+#             */
/*   Updated: 2026/07/21 14:41:17 by ksahinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook
{
private:
	Contact _contacts[8];
	int _totalCount;
	bool isWholeNum(std::string newNum);
	std::string truncateString(std::string str) const;
public:
	PhoneBook();
	bool addNewContact();
	bool searchContact();
	void exitProgram();
};

#endif
