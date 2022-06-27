#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		Form *rrf,*ppf,*scf,*none;
		Bureaucrat gshim("gshim", 1);
		std::cout << std::endl;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender2");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender3");
		none = someRandomIntern.makeForm("something bad", "Bender3");
		std::cout << std::endl;

		gshim.signForm(*rrf);
		gshim.signForm(*ppf);
		gshim.signForm(*scf);
		std::cout << std::endl;

		gshim.executeForm(*rrf);
		gshim.executeForm(*ppf);
		gshim.executeForm(*scf);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		// handle exception
		std::cerr << "Main Exception : " << e.what() << '\n';
	}

}
