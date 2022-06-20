#include "Bureaucrat.hpp"

// 유효하지않은 grade가 들어오면 예외처리한다.
Bureaucrat::Bureaucrat() : name("Annonymous")
{
	grade = 75;
	std::cout << "Bureaucrat Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	try
	{
		if (_grade < 1)
			throw Bureaucrat::GradeTooLowException;
		else if (_grade > 150)
			throw Bureaucrat::GradeTooHighException;
		else
			grade = _grade;

	}
	catch (std::exception &e)
	{

	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& a) : name(a.name)
{
	grade = a.grade;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
	grade = a.grade;
	//name = a.name;	// const라서 바꿀수가 없군..
}
const std::string Bureaucrat::getName(void) const {return name;}
const int Bureaucrat::getGrade(void) const {return grade;}

void IncrementGrade(int _grade)
{
	//if (grade + _grade )
}

void DecrementGrade(int _grade)
{

}