#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "[WrongCat] Default constructor" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "[WrongCat] Copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "[WrongCat] Copy assignment" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "MeowMeowMeowMeowMeowMeow~ (wrong)" << std::endl;
}
