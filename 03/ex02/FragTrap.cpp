#include "FragTrap.hpp"

FragTrap::FragTrap()
	: _health(FragTrap::defaultHealth),
	_energy(FragTrap::defaultEnergy),
	_damage(FragTrap::defaultDamage) {
	std::cerr << "FragTrap constructed" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: _name(name),
	_health(FragTrap::defaultHealth),
	_energy(FragTrap::defaultEnergy),
	_damage(FragTrap::defaultDamage) {
	std::cerr << "FragTrap named \"" << name << "\" constructed" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "FragTrap copied in the image of \"" << src._name << "\"" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap named \"" << this->_name << "\" deconstructed" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
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

std::string		FragTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	FragTrap::getHealth(void) const
{
	return (this->_health);
}

unsigned int	FragTrap::getEnergy(void) const
{
	return (this->_energy);
}

unsigned int	FragTrap::getDamage(void) const
{
	return (this->_damage);
}

int		FragTrap::cantAct(std::string action, std::string name, int health, int energy)
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

void	FragTrap::attack(std::string &target)
{
	if (this->cantAct("attack", this->_name, this->_health, this->_energy))
		return;
	std::string shownTarget = (target == this->_name ? "himself" : target);
	this->_energy--;
	std::cout << this->_name << " does " << this->_damage << " damage to " << shownTarget << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->cantAct("take damage", this->_name, this->_health, this->_energy))
		return;
	if ((int)amount >= this->_health)
		this->_health = 0;
	else
		this->_health -= amount;
	std::cout << this->_name << " takes " << amount << " damage" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->cantAct("get repaired", this->_name, this->_health, this->_energy))
		return;
	this->_health += amount;
	std::cout << this->_name << " heals for " << amount << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (this->cantAct("high five", this->_name, this->_health, 1))
		return;
	std::cout << this->_name << " wants to highfive" << std::endl;
}