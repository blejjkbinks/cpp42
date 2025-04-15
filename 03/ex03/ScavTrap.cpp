#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap("unknown")
{
	this->_health = ScavTrap::defaultHealth;
	this->_energy = ScavTrap::defaultEnergy;
	this->_damage = ScavTrap::defaultDamage;
	std::cerr << "ScavTrap constructed" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	this->_health = ScavTrap::defaultHealth;
	this->_energy = ScavTrap::defaultEnergy;
	this->_damage = ScavTrap::defaultDamage;
	std::cerr << "ScavTrap named \"" << name << "\" constructed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "ScavTrap copied in the image of \"" << src._name << "\"" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap named \"" << this->_name << "\" deconstructed" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
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

void	ScavTrap::guardGate()
{
	if (this->cantAct("guard gate", this->_name, this->_health, 1))
		return;
	std::cout << this->_name << " is guarding the gate" << std::endl;
}

/*
std::string		ScavTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ScavTrap::getHealth(void) const
{
	return (this->_health);
}

unsigned int	ScavTrap::getEnergy(void) const
{
	return (this->_energy);
}

unsigned int	ScavTrap::getDamage(void) const
{
	return (this->_damage);
}

int		ScavTrap::cantAct(std::string action, std::string name, int health, int energy)
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

void	ScavTrap::attack(std::string &target)
{
	if (this->cantAct("attack", this->_name, this->_health, this->_energy))
		return;
	std::string shownTarget = (target == this->_name ? "himself" : target);
	this->_energy--;
	std::cout << this->_name << " does " << this->_damage << " damage to " << shownTarget << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->cantAct("take damage", this->_name, this->_health, this->_energy))
		return;
	if ((int)amount >= this->_health)
		this->_health = 0;
	else
		this->_health -= amount;
	std::cout << this->_name << " takes " << amount << " damage" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->cantAct("get repaired", this->_name, this->_health, this->_energy))
		return;
	this->_health += amount;
	std::cout << this->_name << " heals for " << amount << std::endl;
}
*/