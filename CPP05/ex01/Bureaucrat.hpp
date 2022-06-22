#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <exception>

# include "Form.hpp"

class Bureaucrat
{
private:
	const std::string name;
	const static int DEFAULT_GRADE = 75;
	int grade;

public:
	class GradeTooHighException : public std::exception
	{
		public:
		virtual ~GradeTooHighException() throw();
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual ~GradeTooLowException() throw();
		virtual const char* what() const throw();
	};
	Bureaucrat();								// 기본생성자
	Bureaucrat(std::string _name, int grade) throw (GradeTooHighException, GradeTooLowException);
	Bureaucrat(const Bureaucrat& a);			// 복사생성자
	Bureaucrat& operator=(const Bureaucrat& a);	// 대입연산자
	~Bureaucrat();								// 소멸자


	std::string getName(void) const;
	int getGrade(void) const;
	void IncrementGrade(int _grade) throw (GradeTooHighException, GradeTooLowException);
	void DecrementGrade(int _grade) throw (GradeTooHighException, GradeTooLowException);

	void signForm(Form &ref) throw (GradeTooHighException, GradeTooLowException);
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& a);	// 출력연산자

#endif