#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(Animal const &src);
		Animal(std::string const &type);
		virtual ~Animal();

		Animal	&operator=(Animal const &src);

		std::string const	&getType() const;
		virtual void		makeSound() const;
};

#endif //Animal.hpp