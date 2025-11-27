#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== Array of Animals ===\n";
	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++)
		animals[i]->makeSound();

	for (int i = 0; i < size; i++)
		delete animals[i];

	std::cout << "\n=== Deep copy test ===\n";
	Dog dog1;
	dog1.getBrain()->setIdea(0, "dogdogdog");
	Dog dog2 = dog1; // copy constructor

	dog1.getBrain()->setIdea(0, "catcatcat");

	std::cout << "dog1 idea: "
			<< dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea: "
			<< dog2.getBrain()->getIdea(0) << std::endl;

	return 0;
}

