#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *someZombie = new Zombie(name);

	someZombie->announce();
	return (someZombie);
}