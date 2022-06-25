#include "Intern.hpp"

// const std::string Intern::FormNameArr[3] = {
// 	"presidential pardon",
// 	"robotomy request",
// 	"shrubbery creation"
// };
static Form*	getPresidentialPardonForm(std::string const & target);
static Form*	getRobotomyRequestForm(std::string const & target);
static Form*	getShrubberyCreationForm(std::string const & target);

//=============================================================================
//	Inner Class
//=============================================================================
Intern::NotValidFormException::~NotValidFormException() throw(){}
const char* Intern::NotValidFormException::what() const throw(){return "FormName is Not valid";}

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================

Intern::Intern(){}

Intern::Intern(const Intern& I)
{
	*this = I;
}
Intern& Intern::operator=(const Intern& I)
{
	if(this == &I)
		return *this;

	return *this;
}
Intern::~Intern(){}

//=============================================================================
//	Method
//=============================================================================
Form* Intern::makeForm(std::string fname, std::string target)
{
	Form* ret = NULL;
	typedef Form* (*ptr)(std::string const &target);
	typedef struct {
		std::string form_name;
		ptr ptr;
	} FormTypes;

	FormTypes forms[] =
	{
		{"presidential pardon", &getPresidentialPardonForm},
		{"robotomy request", &getRobotomyRequestForm},
		{"shrubbery creation", &getShrubberyCreationForm}
	};

	for(int i=0;i<3;i++)
	{
		if (forms[i].form_name == fname)
		{
			ret = forms[i].ptr(target);
			std::cout << "Intern creates" << ret->getName() << std::endl;
			return ret;
		}
	}

	// 에러 메시지를 어떻게 보낼지 고민
	//throw NotValidFormException();
	std::cout << "FormName(" << fname << ") is Not Valid" << std::endl;
	return ret;
}

static Form* getPresidentialPardonForm(std::string const &target){return new PresidentialPardonForm(target);}
static Form* getRobotomyRequestForm(std::string const &target){return new RobotomyRequestForm(target);}
static Form* getShrubberyCreationForm(std::string const &target){return new ShrubberyCreationForm(target);}
