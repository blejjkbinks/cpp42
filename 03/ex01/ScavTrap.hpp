#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string	_name;
		int		_health;
		int		_energy;
		int		_damage;

	public:
		static const int	defaultHealth = 100;
		static const int	defaultEnergy = 50;
		static const int	defaultDamage = 20;

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap();

		ScavTrap &operator=(ScavTrap const &src);

		std::string		getName(void) const;
		unsigned int	getHealth(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;
		
		void	attack(std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int	cantAct(std::string action, std::string name, int health, int energy);

		void	guardGate();
};

#endif //ScavTrap.hpp