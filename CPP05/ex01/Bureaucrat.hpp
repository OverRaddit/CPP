#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <exception>

class Bureaucrat //: public exception
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

	void signForm(Bureaucrat b);
	// <bureaucrat> signed <form>
	// <bureaucrat> couldn’t sign <form> because <reason>.
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& a);	// 출력연산자
#endif


/*
Remember. Since grade 1 is the highest one and 150 the lowest,
incrementing a grade 3 should give a grade 2 to the bureaucrat.

이게 무슨말이야...?
*/