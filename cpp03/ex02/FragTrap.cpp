#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Frag_default") {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called (" << name << ")" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap name constructor called (" << this->name << ")" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called (" << name << ")\n";
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " is requesting a positive high five!" << std::endl;
}
