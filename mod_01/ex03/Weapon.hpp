#ifndef WEAPON_H
#define WEAPON_H 

#define DEBUG 1

#include <string>
#include <iostream>

class Weapon {

	private:
        std::string type;

	public:
        Weapon(std::string type);
        ~Weapon();
        const std::string &getType() const;
        void setType(const std::string type);
};

#endif 