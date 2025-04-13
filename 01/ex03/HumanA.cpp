#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
	: name(name), weapon(weapon)
{
	std::cout << "constructing humanA called " << name;
	std::cout << " holding a " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "deconstructing humanA called " << name << std::endl;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}