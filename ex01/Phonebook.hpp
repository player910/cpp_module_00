#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook
{
private:
	Contact _contacts[8];
	int _count;
	int _totalCount;
	bool isWholeNum(std::string newNum);
	std::string truncateString(std::string str) const;
public:
	PhoneBook();
	void addNewContact();
	void searchContact();
	void exitProgram();
};

#endif
