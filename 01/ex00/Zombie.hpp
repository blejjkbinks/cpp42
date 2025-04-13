#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string	_name;
		std::string	_getName();
	
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif //zombie.h