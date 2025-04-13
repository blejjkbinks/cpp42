#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "an unnamed zombie appears" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "a zombie named " << this->_getName() << " appears" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "bye " << this->_getName() << std::endl;
}

std::string Zombie::_getName()
{
	return (this->_name);
}

void	Zombie::announce()
{
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}