#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat A("gshim", 11);
		Form f("First", 10, 5);
		std::cout << std::endl;

		//표준출력
		std::cout << A << std::endl;
		std::cout << f << std::endl;
		std::cout << std::endl;


		// 자격 없이 서명하기
		A.signForm(f);
		std::cout << std::endl;

		// 자격 가지고 서명하기
		A.IncrementGrade(1);
		A.signForm(f);
		std::cout << std::endl;

		//표준출력
		std::cout << A << std::endl;
		std::cout << f << std::endl;
		std::cout << std::endl;

	}
	catch (std::exception &e)
	{
		// handle exception
		std::cerr << "Main Exception : " << e.what() << '\n';
	}

}