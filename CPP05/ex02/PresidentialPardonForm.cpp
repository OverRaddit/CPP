#include "PresidentialPardonForm.hpp"

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", 25, 5, "none")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", 25, 5, target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& a)
{
	*this = a;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& a)
{
	if (this == &a)
		return *this;
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){}

//=============================================================================
//	Method
//=============================================================================

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " execute PresidentialPardonForm(" << getName() << ")!" << std::endl;
	std::cout << getTarget() << "  has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& f)
{
	out << "Name : " << f.getName() << std::endl;
	out << "Signed : " << f.getSign() << std::endl;
	out << "Sign_required : " << f.getSRequired() << std::endl;
	out << "Execute_required : " << f.getERequired() << std::endl;

	return out;
}