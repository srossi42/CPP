#include <iostream>
#include <string.h>

#include "../includes/Phonebook.class.hpp"

int main (void) {

	std::string command;
	Phonebook phonebook;

	while (1) {
		std::cout << "Please enter a command ('ADD', 'SEARCH' or 'EXIT'):" << std::endl;
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0){
			phonebook.addContact();
		}
		else if (command.compare("SEARCH") == 0){
			phonebook.displayContactList();
			if (phonebook.getContactsAmount() > 0){
				phonebook.searchContact();
			}
		}
		else if (command.compare("EXIT") == 0){
			std::cout << "Bye!" << std::endl;
			return 0;
		}
	}
	return 0;
}