#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap	c("ccc");
	ScavTrap	s("sss");
	FragTrap	f("fff");
	DiamondTrap	d("ddd");
	DiamondTrap	b = d;

	s.guardGate();
	f.highFivesGuys();

	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();

	std::string	s_name = "sss";
	//d.attack("sss");
	d.attack(s_name);
	s.takeDamage(DiamondTrap::defaultDamage);

	return (0);
}