#include "Zombie.hpp"

int main()
{
	Zombie *horde = zombieHorde(5, "henry");
	std::cout << "the " << 4 << "th zombie's name is " << horde[1].getName() << std::endl;
	delete[](horde);
	return (0);
}