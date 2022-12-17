#include <string>
#include <iostream>

int main(int argc, char **argv) {
    std::string full_str = "Starting string";
    std::string *stringPTR = &full_str;
    std::string &stringREF = full_str;

    std::cout << "Address of string: '" << &full_str << "'" << std::endl;
    std::cout << "Address held by stringPTR: '" << stringPTR << "'" << std::endl;
    std::cout << "Address held by stringREF: '" << &stringREF << "'" << std::endl;

    std::cout << "Value of string: '" << full_str << "'" << std::endl;
    std::cout << "Value pointed by stringPTR: '" << *stringPTR << "'" << std::endl;
    std::cout << "Value pointer by stringREF: '" << stringREF << "'" << std::endl;

    return (0);
}
