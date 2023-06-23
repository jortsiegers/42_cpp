#include <iostream>
#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (-1);
	}

    ScalarConverter converter;

	converter.convert(argv[1]);

	return (0);
}

// int main(int argc, char **argv)
// {
//     (void)argc;
//     (void)argv;
//     ScalarConverter converter;
//     std::cout << std::endl << "Trying: " << "a" << std::endl;
//     converter.convert("a");
//     std::cout << std::endl << "Trying: " << "1" << std::endl;
//     converter.convert("1");
//     std::cout << std::endl << "Trying: " << "1.0f" << std::endl;
//     converter.convert("1.0f");
//     std::cout << std::endl << "Trying: " << "1.0" << std::endl;
//     converter.convert("1.0");
//     std::cout << std::endl << "Trying: " << "ab" << std::endl;
//     converter.convert("ab");
//     std::cout << std::endl << "Trying: " << "" << std::endl;
//     converter.convert("");

// }

