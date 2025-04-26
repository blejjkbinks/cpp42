#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(), FragTrap(), ScavTrap()
{
	this->_health = DiamondTrap::defaultHealth;
	this->_energy = DiamondTrap::defaultEnergy;
	this->_damage = DiamondTrap::defaultDamage;
	std::cerr << "DiamondTrap constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),
	FragTrap(name + "_frag_name"),
	ScavTrap(name + "_scav_name"),
	_name(name)
{
	this->_health = DiamondTrap::defaultHealth;
	this->_energy = DiamondTrap::defaultEnergy;
	this->_damage = DiamondTrap::defaultDamage;
	std::cerr << "DiamondTrap named \"" << name << "\" constructed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
	: ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap copied in the image of \"" << src._name << "\"" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap named \"" << this->_name << "\" deconstructed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_health = src.getHealth();
		this->_energy = src.getEnergy();
		this->_damage = src.getDamage();
	}
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	if (this->cantAct("wonder who he is", this->_name, this->_health, 1))
		return;
	std::cout << this->_name << " tries to remember his name: " << ClapTrap::_name << std::endl;
}

/*
std::string		DiamondTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	DiamondTrap::getHealth(void) const
{
	return (this->_health);
}

unsigned int	DiamondTrap::getEnergy(void) const
{
	return (this->_energy);
}

unsigned int	DiamondTrap::getDamage(void) const
{
	return (this->_damage);
}

int		DiamondTrap::cantAct(std::string action, std::string name, int health, int energy)
{
	if (health <= 0 || energy <= 0)
	{
		std::cout << name << " cant " << action << ": no ";
		if (health <= 0)
			std::cout << "health" << std::endl;
		else
			std::cout << "energy" << std::endl;
		return (1);
	}
	return (0);
}

void	DiamondTrap::attack(std::string &target)
{
	if (this->cantAct("attack", this->_name, this->_health, this->_energy))
		return;
	std::string shownTarget = (target == this->_name ? "himself" : target);
	this->_energy--;
	std::cout << this->_name << " does " << this->_damage << " damage to " << shownTarget << std::endl;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->cantAct("take damage", this->_name, this->_health, this->_energy))
		return;
	if ((int)amount >= this->_health)
		this->_health = 0;
	else
		this->_health -= amount;
	std::cout << this->_name << " takes " << amount << " damage" << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->cantAct("get repaired", this->_name, this->_health, this->_energy))
		return;
	this->_health += amount;
	std::cout << this->_name << " heals for " << amount << std::endl;
}
*/
