#ifndef PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
private:
	/* data */
public:
//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
	PresidentialPardonForm();											// 기본생성자
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& a);			// 복사생성자
	PresidentialPardonForm& operator=(const PresidentialPardonForm& a);	// 대입연산자
	~PresidentialPardonForm();											// 소멸자

//=============================================================================
//	Method
//=============================================================================
	void execute(Bureaucrat const & executor) const;	// 순수 가상함수
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& f);

#endif