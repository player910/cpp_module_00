#include "Phonebook.hpp"

int main()
{
	PhoneBook phonebook;

	std::string in;
	while (1)
	{
		std::cout << "Write a command: ";
		getline(std::cin, in);
		if (in == "ADD")
		{
			phonebook.addNewContact();
		}
		else if (in == "SEARCH")
		{
			phonebook.searchContact();
		}
		else if (in == "EXIT")
		{
			phonebook.exitProgram();
			break;
		}
	}
}
