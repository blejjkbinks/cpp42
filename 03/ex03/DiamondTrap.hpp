#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;

	public:
		static const int	defaultHealth = 100;
		static const int	defaultEnergy = 50;
		static const int	defaultDamage = 20;

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap();
		DiamondTrap &operator=(DiamondTrap const &src);

		void	whoAmI();
		/*
		std::string		getName(void) const;
		unsigned int	getHealth(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;
		
		void	attack(std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int	cantAct(std::string action, std::string name, int health, int energy);
		*/
};

#endif //DiamondTrap.hpp