#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    return ;
}

PhoneBook::~PhoneBook() {
    return ;
}

void PhoneBook::add_contact() {
    int index = this->total % 8;
    int result = this->contacts[index].insert_values(index);

    if (result == 0) {
        this->total += 1;
    }
}

void PhoneBook::search_contact() {
    int index;
    std::string input;

    for (int i = 0; i < 8; i++) {
        this->contacts[i].display_row();
    }

    std::cout << "Give index: ";
    std::getline(std::cin, input);
    try {
        index = std::stoi(input);
    } catch (std::invalid_argument &e) {
        index = -1;
    } catch (std::out_of_range &e) {
        index = -1;
    }
    if (index < 0 || index >= 8) {
        std::cout << "Invalid index\n";
        return ;
    }
    this->contacts[index].display();
}