#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "DEBUG" << std::endl;
}

void	Harl::info()
{
	std::cout << "INFO" << std::endl;
}

void	Harl::warning()
{
	std::cout << "WARNING" << std::endl;
}

void	Harl::error()
{
	std::cout << "ERROR" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int	index;

	index = -1;
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			index = i;

	switch (index)
	{
		case 0:
			this->debug();
			[[fallthrough]];
		case 1:
			this->info();
			[[fallthrough]];
		case 2:
			this->warning();
			[[fallthrough]];
		case 3:
			this->error();
			break;
		default:
			std::cout << "UNKNOWN COMPLAINT" << std::endl;
	}
}