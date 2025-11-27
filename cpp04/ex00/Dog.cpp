#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[Dog] Default constructor" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "[Dog] Copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog] Copy assignment" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Bow! wow!" << std::endl;
}
