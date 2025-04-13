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
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*f[i])();
			return;
		}
	}
	std::cout << "UNKNOWN COMPLAINT" << std::endl;
}