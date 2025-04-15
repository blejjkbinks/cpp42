#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("unknown"),
	_health(ClapTrap::defaultHealth),
	_energy(ClapTrap::defaultEnergy),
	_damage(ClapTrap::defaultDamage) {
	std::cerr << "ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_health(ClapTrap::defaultHealth),
	_energy(ClapTrap::defaultEnergy),
	_damage(ClapTrap::defaultDamage) {
	std::cerr << "ClapTrap named \"" << name << "\" constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap copied in the image of \"" << src._name << "\"" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap named \"" << this->_name << "\" deconstructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
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

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHealth(void) const
{
	return (this->_health);
}

unsigned int	ClapTrap::getEnergy(void) const
{
	return (this->_energy);
}

unsigned int	ClapTrap::getDamage(void) const
{
	return (this->_damage);
}

int		ClapTrap::cantAct(std::string action, std::string name, int health, int energy)
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

void	ClapTrap::attack(std::string &target)
{
	if (this->cantAct("attack", this->_name, this->_health, this->_energy))
		return;
	std::string shownTarget = (target == this->_name ? "himself" : target);
	this->_energy--;
	std::cout << this->_name << " does " << this->_damage << " damage to " << shownTarget << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->cantAct("take damage", this->_name, this->_health, this->_energy))
		return;
	if ((int)amount >= this->_health)
		this->_health = 0;
	else
		this->_health -= amount;
	std::cout << this->_name << " takes " << amount << " damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->cantAct("get repaired", this->_name, this->_health, this->_energy))
		return;
	this->_health += amount;
	std::cout << this->_name << " heals for " << amount << std::endl;
}