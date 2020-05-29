#include <iostream>
#include <string.h>
#include <iomanip>
#include "../includes/Phonebook.class.hpp"
#include "../includes/Contact.class.hpp"


Phonebook::Phonebook()
{
	this->nb_contacts = 0;
}


Phonebook::~Phonebook()
{
}


Contact *Phonebook::getContact(size_t index){
	return &this->contactsList[index];
}


void Phonebook::addContact(void){
	if (this->nb_contacts < MAX_CONTACTS) {
		Contact *newContact = getContact(this->nb_contacts);
		newContact->set_infos();
		this->nb_contacts++;
	}
	else {
		std::cout << "You cannot add anymore contact, limit has been reached." << std::endl;
	}
	return;
}


size_t Phonebook::getContactsAmount(void) const{
	return this->nb_contacts;
}

	
void Phonebook::displayHeader(void) const{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	return;
}


void Phonebook::displayContactList(void) {
	if (this->nb_contacts > 0){
		displayHeader();
		for (size_t i = 0; i < this->nb_contacts; i++){
			Contact *selected_contact = getContact(i);
			selected_contact->displayAttribute(std::to_string(i), 10, true, false);
			selected_contact->displayAttribute(selected_contact->get_firstname(), 10, true, false);
			selected_contact->displayAttribute(selected_contact->get_lastname(), 10, true, false);
			selected_contact->displayAttribute(selected_contact->get_nickname(), 10, false, false);
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "There is no contact yet. Please add a contact before using the 'SEARCH' command." << std::endl;
	}	
	return;
}


void Phonebook::searchContact(void){
	int index;
	std::cout << "Which contact would like to see? Please enter a valid index:" << std::endl;
	std::cout << "> ";
	while (!(std::cin >> index) || index < 0 || (size_t)index >= this->nb_contacts){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, this contact does not exist." << std::endl;
        std::cout << "Which contact would like to see? Please enter a valid index: " << std::endl; 
        std::cout << "> ";
    }
	Contact *selected_contact = Phonebook::getContact((size_t)index);
	selected_contact->display();
	return;
}
