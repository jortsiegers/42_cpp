#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = NULL; 
    return ;
}

HumanB::~HumanB() {
    return ;
}

void HumanB::attack() const {
    if (this->weapon == NULL) {
        std::cout << this->name << " does not have a weapon to attack with" << std::endl; 
        return ;
    }

    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl; 
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}
