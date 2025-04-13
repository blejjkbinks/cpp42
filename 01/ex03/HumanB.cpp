#include "HumanB.hpp"

HumanB::HumanB()
	: name(""), weapon(nullptr)
{
	std::cout << "constructing unnamed humanB" << std::endl;
}

HumanB::HumanB(const std::string &name)
	: name(name), weapon(nullptr)
{
	std::cout << "constructing a humanB called " << name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "deconstructing humanB called " << name << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their ";
	if (weapon && weapon->getType() != "")
		std::cout << weapon->getType();
	else
		std::cout << "bare hands";
	std::cout << "." << std::endl;
}