#include "ShrubberyCreationForm.hpp"

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137, "none")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137, target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a)
{
	*this = a;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& a)
{
	if (this == &a)
		return *this;
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

//=============================================================================
//	Method
//=============================================================================

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " execute ShrubberyCreationForm(" << getName() << ")!" << std::endl;

	std::string filename(getTarget() + "_shrubbery");
	std::ofstream writeFile(filename);	// 가끔 공간이없어서 실패함

	if(!writeFile.is_open()){
		std::cout << "FILE OPEN ERROR" << std::endl;
		return ;
	}
	writeFile << "        t" << "\n";
	writeFile << "       .#." << "\n";
	writeFile << "      .###." << "\n";
	writeFile << "     .#%##%." << "\n";
	writeFile << "    .%##%###." << "\n";
	writeFile << "   .##%###%##." << "\n";
	writeFile << "  .#%###%##%##." << "\n";
	writeFile << "        #" << "\n";
	writeFile << "        #" << "\n";
	writeFile.close();
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& f)
{
	out << "Name : " << f.getName() << std::endl;
	out << "Signed : " << f.getSign() << std::endl;
	out << "Sign_required : " << f.getSRequired() << std::endl;
	out << "Execute_required : " << f.getERequired() << std::endl;

	return out;
}