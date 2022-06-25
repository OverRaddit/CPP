#include "ShrubberyCreationForm.hpp"

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137, "none")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 25, 5, target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a)
{
	(void)a;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& a)
{
	(void)a;
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

//=============================================================================
//	Method
//=============================================================================

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " execute ShrubberyCreationForm(" << getName() << ")!" << std::endl;
	std::string filename(getName() + "_shrubbery");
	std::cout << filename << std::endl;
	std::ofstream writeFile(filename);
	//std::ofstream writeFile("shrubbery");
	if(!writeFile.is_open()){
		std::cout << "FILE OPEN ERROR" << std::endl;
		//return (-1);
		return ;
	}
	std::cout << "[DEBUG]" << std::endl;
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