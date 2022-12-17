#include <string>
#include <cstring>
#include <iostream>


int main(int argc, char **argv)
{
    
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++) {
        for (int p = 0; p < strlen(argv[i]); p++) {
            std::cout << (char)std::toupper(argv[i][p]);
        }
    }
    std::cout << std::endl;
    return 0;
}