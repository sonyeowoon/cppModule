#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("unknown") {}

Zombie::Zombie(const std::string &s) : name(s) {}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " is destroyed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
