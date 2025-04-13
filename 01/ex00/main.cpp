#include "Zombie.hpp"

int main()
{
	Zombie *a = newZombie("A");
	a->announce();
	delete(a);
	randomChump("B");
	return (0);
}