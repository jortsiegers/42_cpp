#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type){
    return ;
}

Weapon::~Weapon() {
    return ;
}

const std::string &Weapon::getType() const {
    return this->type;
}

void Weapon::setType(const std::string type) {
    this->type = type;
}