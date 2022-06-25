#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool sign;
	const int sign_required;
	const int execute_required;
	// ex02
	std::string target;
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

	//ex02
	class DoubleSignException : public std::exception
	{
		public:
		virtual ~DoubleSignException() throw();
		virtual const char* what() const throw();
	};
	class NoSignException : public std::exception
	{
		public:
		virtual ~NoSignException() throw();
		virtual const char* what() const throw();
	};
//=============================================================================
//	Getter
//=============================================================================
	std::string getName() const;
	bool getSign() const;
	int getSRequired() const;
	int getERequired() const;
	std::string getTarget() const;

//=============================================================================
//	method
//=============================================================================
	void beSigned(Bureaucrat& b) throw (DoubleSignException, GradeTooLowException);	// 공무원의 등급이 적절하다면 서명한다.

	// [EX02] throw 붙일거 처리해주자.
	bool isSignable(Bureaucrat& b) const throw (DoubleSignException, GradeTooLowException);
	bool isExecutable(Bureaucrat& b) const throw (NoSignException, GradeTooLowException);
	virtual void execute(Bureaucrat const & executor) const = 0;	// 순수 가상함수

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================

	Form();							// 기본생성자
	Form(std::string _name, int sign, int execute, std::string target) throw (GradeTooHighException, GradeTooLowException);
	Form(const Form& a);			// 복사생성자
	Form& operator=(const Form& a);	// 대입연산자
	~Form();						// 소멸자
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
