#include "Bureaucrat.hpp"


Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){};
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHigh!!";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLow!!";
};

Bureaucrat::Bureaucrat() : name("Annonymous")
{
	std::cout << "Bureaucrat Constructor" << std::endl;
	grade = DEFAULT_GRADE;
}

// [4]
Bureaucrat::Bureaucrat(std::string _name, int _grade)
	throw (GradeTooHighException, GradeTooLowException)
	: name(_name)
{
	try
	{
		std::cout << "Bureaucrat(name, grade) Constructor" << std::endl;
		if (_grade < 1)
			throw GradeTooHighException();	// [3]
		else if (_grade > 150)
			throw GradeTooLowException();
		else
			grade = _grade;
	}
	catch (std::exception &e)
	{
		std::cerr << "constructor Exception: " << e.what() << std::endl;
		grade = DEFAULT_GRADE;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& a) : name(a.name), grade(a.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
	grade = a.grade;
	(*(const_cast<std::string *>(&name))) = a.getName();
	return *this;
}
std::string Bureaucrat::getName(void) const {return name;}
int Bureaucrat::getGrade(void) const {return grade;}

void Bureaucrat::IncrementGrade(int _grade)
	throw (GradeTooHighException, GradeTooLowException)
{
	std::cout << "IncrementGrade(grade) Func" << std::endl;
	try
	{
		if (1 + _grade > grade)
			throw GradeTooHighException();
		else if (150 + _grade < grade)
			throw GradeTooLowException();
		else
			grade -= _grade;
	}
	catch (std::exception &e)
	{
		std::cerr << "IncrementGrade Exception: " << e.what() << std::endl;
	}
}

void Bureaucrat::DecrementGrade(int _grade)
	throw (GradeTooHighException, GradeTooLowException)
{
	std::cout << "DecrementGrade(grade) Func" << std::endl;
	try
	{
		if (1 - _grade > grade)
			throw GradeTooHighException();
		else if (150 - _grade < grade)
			throw GradeTooLowException();
		else
			grade += _grade;
	}
	catch (std::exception &e)
	{
		std::cerr << "DecrementGrade Exception: " << e.what() << std::endl;
	}

}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& a)
{
	// [<name>, bureaucrat grade <grade>.]
	std::cout << a.getName() << ", bureaucrat grade " << a.getGrade();

	// look nice
	//std::cout << std::setw(10) << a.getName() << ", bureaucrat grade " << a.getGrade();
	return out;
}