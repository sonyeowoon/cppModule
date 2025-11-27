#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
	std::cout << "[Dog] Default constructor" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "[Dog] Copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog] Copy assignment" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor" << std::endl;
	delete brain;
}

void	Dog::makeSound() const {
	std::cout << "Bow! wow!" << std::endl;
}

Brain*	Dog::getBrain() const {
	return brain;
}
