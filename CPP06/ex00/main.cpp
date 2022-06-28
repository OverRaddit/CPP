#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Convert.hpp"

int main(int argc, char *argv[])
{
	if (!argv[1])
	{
		std::cout << "There's no argument! Exit program.." << std::endl;
		return (0);
	}

	try
	{
		(void)argc;
		// std::cout << static_cast<char>(argv[0]) << std::endl;
		// std::cout << static_cast<int>(argv[0]) << std::endl;
		// std::cout << static_cast<float>(argv[0]) << std::endl;
		// std::cout << static_cast<double>(argv[0]) << std::endl;

		// char string[] = "12.24 23.23 34.34";
		// char *pEnd;
		// double a,b,c;
		// a = std::strtod(string, &pEnd);
		// b = std::strtod(pEnd, &pEnd);
		// c = std::strtod(pEnd, NULL);

		// printf("%.2f %.2f %.2f\n",a,b,c);

		// printf("char : %c\n",  static_cast<char>(a));
		// printf("int : %d\n", static_cast<int>(a) );
		// printf("float : %f\n",  static_cast<float>(a));
		//printf("double : %d");

		Convert A(argv[1]);

		A.printAll();

	}
	catch (std::exception &e)
	{
		// handle exception
		std::cerr << "Main Exception : " << e.what() << '\n';
	}

}