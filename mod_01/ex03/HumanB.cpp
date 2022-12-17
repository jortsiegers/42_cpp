#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
    this->weapon = NULL; 
    return ;
}

HumanB::~HumanB() {
    if (DEBUG)
        std::cout << "Human with name: '" << this->name << "' destructed" << std::endl;
    return ;
}

void HumanB::attack() const {
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl; 
    return ;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
    return ;
}
