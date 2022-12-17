#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type){
    return ;
}

Weapon::~Weapon() {
    if (DEBUG)
        std::cout << "Weapon with type: '" << this->type << "' destructed" << std::endl;
}

const std::string &Weapon::getType() const {
    return this->type;
}

void Weapon::setType(const std::string type) {
    this->type = type;
}