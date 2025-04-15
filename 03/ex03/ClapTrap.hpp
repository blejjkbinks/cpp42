#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int		_health;
		int		_energy;
		int		_damage;

	public:
		static const int	defaultHealth = 10;
		static const int	defaultEnergy = 10;
		static const int	defaultDamage = 0;

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &src);

		std::string		getName(void) const;
		unsigned int	getHealth(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;
		
		void	attack(std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int	cantAct(std::string action, std::string name, int health, int energy);
};

#endif //ClapTrap.hpp