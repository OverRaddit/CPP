#include "Form.hpp"

//=============================================================================
//	Getter
//=============================================================================
std::string Form::getName(){return name;}
bool Form::getSign(){return sign;}
int Form::getSRequired(){return sign_required;}
int Form::getERequired(){return execute_required;}

//=============================================================================
//	method
//=============================================================================
void Form::beSigned(Bureaucrat b)
{
	try
	{
		if (sign_required < b.getGrade())
			throw GradeTooLowException();
		else
		{
			sign = true;
			b.signForm(name, sign, 0);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "[ERROR]in beSigned() " << e.what() << '\n';
		b.signForm(name, sign, e);

	}
}

void Form::print_info(void)
{
	std::cout << "Name : " << name << std::endl;
	std::cout << "Signed : " << sign << std::endl;
	std::cout << "Sign_required : " << sign_required << std::endl;
	std::cout << "Execute_required : " << execute_required << std::endl;
}

// 멤버 함수가 아니라 Form데이터에 접근하려면 getter가 필요할 것 같다.
// 서브젝트에서 getter를 요구하는가?
// 그렇다.
//std::ostream& operator<<(std::ostream& out, const Form& f)
// {
// 	std::cout << "Name : " << f.name << std::endl;
// 	std::cout << "Signed : " << f.sign << std::endl;
// 	std::cout << "Sign_required : " << f.sign_required << std::endl;
// 	std::cout << "Execute_required : " << f.execute_required << std::endl;
// 	return out;
// }

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
Form::Form()
	: name("annonymous"), sign(false), sign_required(20), execute_required(10)
{}

Form::Form(std::string _name, int sign, int execute)
	throw (GradeTooHighException, GradeTooLowException)
	: name(_name), sign(false), sign_required(sign), execute_required(execute)
{
	// 구현필요...
}