#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat A("gshim", 1);
		PresidentialPardonForm P;
		RobotomyRequestForm R;
		ShrubberyCreationForm S;
		std::cout << std::endl;

		//표준출력
		std::cout << A << std::endl;
		std::cout << P << std::endl;
		std::cout << R << std::endl;
		std::cout << S << std::endl;
		std::cout << std::endl;


		// 자격 없이 서명하기
		A.signForm(P);
		std::cout << std::endl;

		// 자격 가지고 서명하기
		A.IncrementGrade(1);
		A.signForm(P);

		//A.executeForm(R); // 서명안된 폼 실행
		A.executeForm(P);
		std::cout << std::endl;

		//표준출력
		std::cout << A << std::endl;
		std::cout << P << std::endl;
		std::cout << std::endl;

	}
	catch (std::exception &e)
	{
		// handle exception
		std::cerr << "Main Exception : " << e.what() << '\n';
	}

}