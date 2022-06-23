#ifndef ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
private:
	/* data */
public:
//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
	RobotomyRequestForm();											// 기본생성자
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& a);				// 복사생성자
	RobotomyRequestForm& operator=(const RobotomyRequestForm& a);	// 대입연산자
	~RobotomyRequestForm();											// 소멸자

//=============================================================================
//	Method
//=============================================================================
	void execute(Bureaucrat const & executor) const;	// 순수 가상함수

};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& f);

#endif