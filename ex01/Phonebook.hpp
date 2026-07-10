#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];
	int _count;
	int _current_user;
	bool isWholeNum(std::string newNum);
public:
	PhoneBook();
	void addNewContact();
	void searchContact();
	void exitProgram();
};

#endif
