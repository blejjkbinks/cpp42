#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::string	fragTrapName = "FT-356";
	std::string scavTrapName = "SCVT-2000";
	std::string clapTrapName = "CT-42";

	FragTrap	fragTrap(fragTrapName);
	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	fragTrap.highFivesGuys();
	clapTrap.attack(scavTrapName);
	scavTrap.takeDamage(ClapTrap::defaultDamage);
	scavTrap.attack(fragTrapName);
	fragTrap.takeDamage(ScavTrap::defaultDamage);
	fragTrap.beRepaired(5);
	scavTrap.guardGate();
	for (int i = 0; i < 4; i++) {
		fragTrap.attack(scavTrapName);
		scavTrap.takeDamage(FragTrap::defaultDamage);
	}
	scavTrap.beRepaired(20);
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(5000);
	fragTrap.highFivesGuys();
	return (0);
}