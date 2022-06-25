#ifndef INTERN_HPP
# define INTERN_HPP

//# include "Form.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# include <exception>
# include <string>

class Intern
{
private:
	const static std::string FormNameArr[3];

public:
//=============================================================================
//	Inner Class
//=============================================================================
	class NotValidFormException : public std::exception
	{
		public:
		virtual ~NotValidFormException() throw();
		virtual const char* what() const throw();
	};
//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
	Intern();							// 기본생성자
	Intern(const Intern& I);			// 복사생성자
	Intern& operator=(const Intern& I);	// 대입연산자
	~Intern();							// 소멸자
//=============================================================================
//	Method
//=============================================================================

	Form* makeForm(std::string fname, std::string target);

};


#endif
