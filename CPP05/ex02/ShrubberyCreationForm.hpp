#ifndef SHRUBBERYCREATIONFORM_HPP

# include <fstream> // 파일입출력
# include "Bureaucrat.hpp"
class ShrubberyCreationForm : public Form
{
private:
	/* data */
public:
//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
	ShrubberyCreationForm();											// 기본생성자
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& a);				// 복사생성자
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& a);	// 대입연산자
	~ShrubberyCreationForm();											// 소멸자

//=============================================================================
//	Method
//=============================================================================
	void execute(Bureaucrat const & executor) const;	// 순수 가상함수

};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& f);

#endif