#include "Weapon.hpp"

Weapon::Weapon() : type("")
{
	std::cout << "constructing weapong with no name" << std::endl;
	return;
}

Weapon::Weapon(const std::string &type) : type(type)
{
	std::cout << "construcing a weapon shaped like a " << type << std::endl;
	return;
}

Weapon::~Weapon()
{
	std::cout << "deconstructing weapon" << std::endl;
	return;
}

const std::string	&Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const std::string &newType)
{
	type = newType;
}