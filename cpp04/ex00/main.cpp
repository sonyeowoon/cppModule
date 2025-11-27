#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Normal Animals ===\n";
	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	cat->makeSound(); // Cat 소리
	dog->makeSound(); // Dog 소리
	meta->makeSound(); // Animal 소리

	delete meta;
	delete dog;
	delete cat;

	std::cout << "\n=== Wrong Animals ===\n";
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << wc->getType() << std::endl;
	wc->makeSound();      // ❗ WrongAnimal::makeSound 호출됨
	wmeta->makeSound();

	delete wmeta;
	delete wc;

	return 0;
}

