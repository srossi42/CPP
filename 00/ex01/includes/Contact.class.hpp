#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>

class Contact {

private :
	std::string infos[11];

public: 
	Contact(void);
	~Contact(void);

	std::string     get_firstname(void) const;
	std::string     get_lastname(void) const;
    std::string     get_nickname(void) const;
    void 			display(void);
    void 			displayAttribute(std::string attribute, size_t max, bool col, bool align_left) const;
    void            set_contact_info(int index, std::string info);
	void 			set_infos(void) ;
};

#endif