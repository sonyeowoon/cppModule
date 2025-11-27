#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unknown"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called (" << name << ")" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap name constructor called (" << this->name << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	hitPoints(other.hitPoints),
	energyPoints(other.energyPoints),
	attackDamage(other.attackDamage) 
{
	std::cout << "ClapTrap copy constructor called (" << name << ")" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called (" << name << ")\n";
}

void	ClapTrap::attack(const std::string &target) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't attack because it is out of hit points..." << std::endl;
		return ;
	}
	if (energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't attack because it has no energy points..." << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target
			<< ", causing " << attackDamage << " points of damage! (EP left: "
			<< energyPoints << ")" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is already destroyed..." << std::endl;
		return ;
	}
	int damage = static_cast<int>(amount);
	hitPoints -= damage;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " takes " << damage
			<< " points of damage! (HP: " << hitPoints << ")" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't be repaired because it is destroyed..." << std::endl;
		return ;
	}
	if (energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't repair because it has no energy points..." << std::endl;
		return ;
	}
	int repair = static_cast<int>(amount);
	energyPoints--;
	hitPoints += repair;
	std::cout << "ClapTrap " << name << " is rapaired by " << repair << " points! (HP: "
			<< hitPoints << ", EP left: " << energyPoints << ")" << std::endl;
}

void	ClapTrap::printStatus() const {
	std::cout << "[ClapTrap Status] "
			<< "name: " << name
			<< ", HP: " << hitPoints
			<< ", EP: " << energyPoints
			<< ", AD: " << attackDamage << "\n";
}
