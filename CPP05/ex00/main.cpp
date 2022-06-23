#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat A("gshim", 10);
		// 유효하지 않은 grade로 생성자 호출
		Bureaucrat B("Mr.0", 0);
		Bureaucrat C("Minus", 1500);

		// 복사
		// std::cout << "A"<< A << std::endl;
		// std::cout << "B"<< B << std::endl;
		// A = B;
		// std::cout << "A"<< A << std::endl;
		// std::cout << "B"<< B << std::endl;
		// std::cout << std::endl;

		//표준출력
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;
		std::cout << std::endl;

 		// 유효범위보다 큰 grade로 증감연산
		A.IncrementGrade(11);
		A.IncrementGrade(10);
		A.DecrementGrade(141);

		A.IncrementGrade(9);	// A's grade 10 -> 1
		//A.DecrementGrade(-9);	// 둘은 다른함수에서 완벽히 동일한 연산을 수행한다.

		std::cout << std::endl;

 		// 유효범위보다 작은 grade로 차감연산
		//A.DecrementGrade(150);

		//표준출력
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;
		std::cout << std::endl;

	}
	catch (std::exception &e)
	{
		// handle exception
		std::cerr << "Main Exception : " << e.what() << '\n';
	}

}