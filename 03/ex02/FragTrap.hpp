#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		std::string	_name;
		int		_health;
		int		_energy;
		int		_damage;

	public:
		static const int	defaultHealth = 100;
		static const int	defaultEnergy = 100;
		static const int	defaultDamage = 30;

		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		~FragTrap();

		FragTrap &operator=(FragTrap const &src);

		std::string		getName(void) const;
		unsigned int	getHealth(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;
		
		void	attack(std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int	cantAct(std::string action, std::string name, int health, int energy);

		void	highFivesGuys();
};

#endif //FragTrap.hpp