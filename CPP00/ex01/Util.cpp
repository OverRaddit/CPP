#include <cstdio> // void clearerr(FILE* stream);
#include <iostream>

void	validate_input(void)
{
	if (std::cin.eof() || std::cin.fail())
	{
		std::cout << "Input Fail\n";
		std::cin.clear();
		clearerr(stdin);	// 표준입력fd 0
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}