#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Scav_default") {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called (" << name << ")" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap name constructor called (" << this->name << ")" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called (" << name << ")" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called (" << name << ")\n";
}

void	ScavTrap::attack(const std::string &target) {
	if (hitPoints <= 0) {
		std::cout << "ScavTrap " << name << " can't attack because it is out of hit points..." << std::endl;
		return ;
	}
	if (energyPoints <= 0) {
		std::cout << "ScavTrap " << name << " can't attack because it has no energy points..." << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " strongly attacks " << target
			<< ", causing " << attackDamage << " points of damage! (EP left: "
			<< energyPoints << ")" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
