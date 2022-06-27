#include "Bureaucrat.hpp"

//=============================================================================
//	Inner Class
//=============================================================================

Form::GradeTooHighException::~GradeTooHighException() throw(){};
Form::GradeTooLowException::~GradeTooLowException() throw(){};
Form::DoubleSignException::~DoubleSignException() throw(){};

const char* Form::GradeTooHighException::what() const throw()
{return "GradeTooHighException";}

const char* Form::GradeTooLowException::what() const throw()
{return "GradeTooLowException";}

const char* Form::DoubleSignException::what() const throw()
{return "DoubleSignException";}

//=============================================================================
//	Getter
//=============================================================================
std::string Form::getName()const {return name;}
bool Form::getSign()const {return sign;}
int Form::getSRequired()const {return sign_required;}
int Form::getERequired()const {return execute_required;}

//=============================================================================
//	method
//=============================================================================

// 서명을 하고 서명 할 수 없으면 예외데이터를 던진다.
// 여기서 b가 스택에 생성되는데 이 함수가 종료될때 b가 삭제되니 그때도 소멸자가 호출된다.
void Form::beSigned(Bureaucrat& b)
	throw (DoubleSignException, GradeTooLowException)
{
	if (sign)
		throw DoubleSignException();
	else if (sign_required < b.getGrade())
		throw GradeTooLowException();
	else
	{
		sign = true;
	}
}

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
	try
	{
		std::cout << "Form(name, sign, execute) Constructor" << std::endl;
		if (sign < 1 || execute < 1)
			throw GradeTooHighException();
		else if (sign > 150 || execute > 150)
			throw GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << "Form constructor Exception: " << e.what() << std::endl;

	}
}

Form::Form(const Form& a) : name(a.name), sign(a.sign), sign_required(a.sign_required), execute_required(a.execute_required)
{
	*this = a;
}

Form& Form::operator=(const Form& a)
{
	// 의미있는 복사가 맞나...?
	sign = a.sign;
	return *this;
}

Form::~Form()
{

}

//=============================================================================
//	ETC...
//=============================================================================

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << "Name : " << f.getName() << std::endl;
	out << "Signed : " << f.getSign() << std::endl;
	out << "Sign_required : " << f.getSRequired() << std::endl;
	out << "Execute_required : " << f.getERequired() << std::endl;

	return out;
}
