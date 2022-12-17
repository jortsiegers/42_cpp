#include "Harl.hpp"

int main() {
	Harl harl;


    for (int i = 0; i < 4; i++) {
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
    }
    harl.complain("");
    harl.complain("hello");
    harl.complain("aaaahhhhhh");
    return 0;
}