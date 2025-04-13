#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie someChump = Zombie(name);

	someChump.announce();
	return ;
}