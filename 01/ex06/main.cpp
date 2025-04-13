#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	o;

	if (argc != 2)
	{
		std::cout << "usage: " << argv[0] << " <level>" << std::endl;
		return (1);
	}
	o.complain(argv[1]);

	return (0);
}