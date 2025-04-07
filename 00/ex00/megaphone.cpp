#include <iostream>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) { 
			char c = argv[i][j];
			if ('a' <= c && c <= 'z')
				c -= ('a' - 'A');
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return 0;
}
