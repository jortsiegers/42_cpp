#include "Zombie.hpp"


void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main(int argc, char **argv) {
    Zombie *zombie;

    zombie = newZombie("Tom");
    zombie->announce();
    delete zombie;

    randomChump("Chris");
    return (0);
}