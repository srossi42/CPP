#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"

const int MAX_CONTACTS = 8;

class Phonebook {
public: 

	Phonebook(void);
	~Phonebook(void);
	
	Contact *getContact(size_t index);
	size_t	getContactsAmount(void) const;
	void	addContact(void);
	void	searchContact(void);
	void	displayHeader(void) const;
	void	displayContactList(void);

private:
	Contact contactsList[MAX_CONTACTS];
	std::string fields[11];
	size_t nb_contacts;
};

#endif