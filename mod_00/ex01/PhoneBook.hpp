#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.hpp"

class PhoneBook{

	private:
        Contact     contacts[8];
        int         total;

	public:
        PhoneBook();
        ~PhoneBook();
        void add_contact();
        void search_contact();

};

#endif 