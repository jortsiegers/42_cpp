#include "Zombie.hpp"

Zombie::Zombie() {
    return ;
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << this->name << ": Bye Bye arggggggg...\n";
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}


void Zombie::nameSet(std::string name) {
    this->name = name;
}