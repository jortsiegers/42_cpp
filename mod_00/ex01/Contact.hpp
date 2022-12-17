#ifndef CONTACT_H 
#define CONTACT_H
#include <string>
#include <iostream>

class Contact {


	public:
		Contact(void);
		~Contact(void);
        void display();
        void display_row();
        int insert_values(int index);


	private:
        void print_column(std::string value);
        int         index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

};

#endif 