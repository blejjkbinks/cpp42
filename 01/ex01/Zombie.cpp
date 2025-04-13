#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "an unnamed zombie appears" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "a zombie named " << this->getName() << " appears" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "bye " << this->getName() << std::endl;
}

std::string Zombie::getName()
{
	return (this->_name);
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce()
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}