#include <iostream>
#include "../includes/Contact.class.hpp"

std::string 	fields[11] = {"First name*", "Last name*", "Nickname*", "Login",
                            "Postal address", "Email address", "Phone number",
                            "Birthday date", "Favorite_meal", "Underwear color",
                            "Darkest secret"};


				Contact::Contact(void){
	return;
};

				Contact::~Contact(void){
	return;
};

void            Contact::set_contact_info(int index, std::string info){
	this->infos[index] = info;
};

void 			Contact::display(void) {
	for (size_t i = 0; i < 11; i++) {
		displayAttribute(fields[i], 16, false, true);
		std::cout << this->infos[i] << std::endl;
	}
}


void 			Contact::displayAttribute(std::string attribute, size_t max, bool col, bool align_left) const{
	size_t len = attribute.length();
	if (len > max) {
		attribute.resize(max-1);
		std::cout << attribute;
		std::cout << '.';
	}
	else {
		if (!align_left) {
			for (size_t i = max; i > len; i--) {
				std::cout << ' ';
			}
			std::cout << attribute;
		}
		else {
			std::cout << attribute << ':';
			for (size_t i = max; i > len; i--) {
				std::cout << ' ';
			}
		}
	}
	if (col){
		std::cout << '|';
	}
	return;
}


void 			Contact::set_infos(void) {
	std::string input;
	for (size_t i=0; i<11; i++) {
		input = "";
		std::cout << fields[i] << ":" << std::endl;
		std::cout << "> ";
		if (i < 3) {
			while (input.length() == 0) {
				std::getline(std::cin >> std::ws, input);
			}
		}
		else {
			std::getline(std::cin, input);
		}
		
		set_contact_info(i, input);
	}
	return;
}

std::string     Contact::get_firstname(void) const{
	return this->infos[0];	
};

std::string     Contact::get_lastname(void) const{
	return this->infos[1];	
};

std::string     Contact::get_nickname(void) const{
	return this->infos[2];	
};




