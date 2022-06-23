#include "RobotomyRequestForm.hpp"

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", 25, 5, "none")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("RobotomyRequestForm", 25, 5, target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& a)
{
	(void)a;

}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& a)
{
	(void)a;
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){}

//=============================================================================
//	Method
//=============================================================================

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::cout << "DEBUG" << std::endl;
	std::cout << executor.getName() << std::endl;
	std::cout << getName() << std::endl;

	std::cout << executor.getName() << " execute RobotomyRequestForm(" << getName() << ")!" << std::endl;
	std::srand(std::time(nullptr));
	// for(int i=0;i<10;i++)
	// {
	// 	std::cout << std::rand() << std::endl;
	// }
	int success = std::rand() % 2;

	// 성공
	if (success)
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& f)
{
	out << "Name : " << f.getName() << std::endl;
	out << "Signed : " << f.getSign() << std::endl;
	out << "Sign_required : " << f.getSRequired() << std::endl;
	out << "Execute_required : " << f.getERequired() << std::endl;

	return out;
}