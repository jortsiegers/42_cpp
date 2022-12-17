#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(int argc, char **argv) {
    Zombie *zombie = zombieHorde(10, "Mario");

    std::cout << "First zombie should announce:" << std::endl;
    zombie->announce();
    std::cout << "All zombies should announce:" << std::endl;
    for (int i = 0; i < 10; i++) {
        zombie[i].announce();
    }
    std::cout << "All zombies should deconstruct:" << std::endl;
    delete [] zombie; 

    return (0);
}