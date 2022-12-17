#include <string>
#include <iostream>

int main(int argc, char **argv) {
    std::string full_str = "HI THIS IS BRAIN";
    std::string *stringPTR = &full_str;
    std::string &stringREF = full_str;

    std::cout << "Address of string: \t\t'" << &full_str << "'" << std::endl;
    std::cout << "Address held by stringPTR: \t'" << stringPTR << "'" << std::endl;
    std::cout << "Address held by stringREF: \t'" << &stringREF << "'" << std::endl << std::endl;

    std::cout << "Value of string: \t\t'" << full_str << "'" << std::endl;
    std::cout << "Value pointed by stringPTR: \t'" << *stringPTR << "'" << std::endl;
    std::cout << "Value pointer by stringREF: \t'" << stringREF << "'" << std::endl;

    return (0);
}
