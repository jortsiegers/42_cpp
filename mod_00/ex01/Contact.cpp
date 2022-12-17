#include "Contact.hpp"


Contact::Contact(void) {
    this->index = -1;
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

Contact::~Contact(void) {
    return ;
}

void Contact::display(void) {
    if (this->index == -1) {
        std::cout << "Invalid index\n";
        return ;
    }
    std::cout << "First name: " << this->first_name << std::endl;
    std::cout << "Last name: " << this->last_name << std::endl;
    std::cout << "Nick name: " << this->nickname << std::endl;
    std::cout << "Phone number: " << this->phone_number << std::endl;
    std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}


void Contact::display_row(void) {
    std::string index;
    if (this->index == -1) {
        index = "";
    } else {
        index = std::to_string(this->index);
    }
    std::cout << "|";
    this->print_column(index);
    std::cout << "|";
    this->print_column(this->first_name);
    std::cout << "|";
    this->print_column(this->last_name);
    std::cout << "|";
    this->print_column(this->nickname);
    std::cout << "|" << std::endl;
}

void Contact::print_column(std::string value) {
    int start = 10 - value.length();
    start = (start < 0) ? 0 : start;
    for (int i = 0; i < 10; i++) {
        if (i == 9 && value.length() > 10) {
            std::cout << ".";
        } else if (i >= start) {
            std::cout << value[i - start];
        } else {
            std::cout << " ";
        }
    }
}

int Contact::insert_values(int index) {

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "First name: ";
    std::getline(std::cin, first_name);
    if (first_name == "") {
        std::cout << "Empty values not allowed\n";
        return 1;
    }

    std::cout << "Last name: ";
    std::getline(std::cin, last_name);
    if (last_name == "") {
        std::cout << "Empty values not allowed\n";
        return 1;
    }

    std::cout << "Nick name: ";
    std::getline(std::cin, nickname);
    if (nickname == "") {
        std::cout << "Empty values not allowed\n";

        return 1;
    }

    std::cout << "Phone number: ";
    std::getline(std::cin, phone_number);
    if (phone_number == "") {
        std::cout << "Empty values not allowed\n";
        return 1;
    }

    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkest_secret);
    if (darkest_secret == "") {
        std::cout << "Empty values not allowed\n";
        return 1;
    }

    this->index = index;    
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
    return (0);
}

