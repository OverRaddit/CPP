#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool sign;
	const int sign_required;
	const int execute_required;
public:
//=============================================================================
//	Inner Class
//=============================================================================
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
//=============================================================================
//	Getter
//=============================================================================
	std::string getName();
	bool getSign();
	int getSRequired();
	int getERequired();

//=============================================================================
//	method
//=============================================================================
	void beSigned(Bureaucrat b);	// 공무원의 등급이 적절하다면 서명한다.
	void print_info();


//=============================================================================
//	Orthodox Canonical Form
//=============================================================================

	Form();							// 기본생성자
	Form(std::string _name, int sign, int execute)
		throw (GradeTooHighException, GradeTooLowException);
	Form(const Form& a);			// 복사생성자
	Form& operator=(const Form& a);	// 대입연산자
	~Form();						// 소멸자
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif