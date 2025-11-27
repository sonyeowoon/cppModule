#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
	std::cout << "[Cat] Default constructor" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "[Cat] Copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "[Cat] Copy assignment" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor" << std::endl;
	delete brain;
}

void	Cat::makeSound() const {
	std::cout << "Meow~" << std::endl;
}

Brain*	Cat::getBrain() const {
	return brain;
}
