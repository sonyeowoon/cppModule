#include "Cat.hpp"

Cat::Cat() {
	std::cout << "[Cat] Default constructor" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "[Cat] Copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "[Cat] Copy assignment" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow~" << std::endl;
}
