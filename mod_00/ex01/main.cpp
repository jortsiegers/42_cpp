#include <string>
#include <cstring>
#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"


void    search_contact()
{

    return ;
}

int main(int argc, char **argv)
{
    PhoneBook phone_book;
    std::string command;

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phone_book.add_contact();
        else if (command == "SEARCH")
            phone_book.search_contact();
        else if (command == "EXIT")
            break;
    }
    return (0);
}




