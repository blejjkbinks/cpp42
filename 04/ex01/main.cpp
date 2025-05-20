#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " ";
	j->makeSound();

	std::cout << i->getType() << " ";
	i->makeSound();

	meta->makeSound();

	std::cout << "----- WrongAnimal tests -----\n";

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " ";
	wrongCat->makeSound();

	wrong->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongCat;

	return 0;
}
