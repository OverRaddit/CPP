#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		Form* rrf;

		rrf = someRandomIntern.makeForm("robotomy request1", "Bender");
	}
	catch (std::exception &e)
	{
		// handle exception
		std::cerr << "Main Exception : " << e.what() << '\n';
	}

}
