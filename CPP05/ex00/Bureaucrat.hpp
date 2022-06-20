#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat : public exception
{
private:
	const std::string name;
	int grade;

	std::exception GradeTooHighException;
	std::exception GradeTooLowException;
public:
	Bureaucrat();								// 기본생성자
	Bureaucrat(std::string _name, int grade);
	Bureaucrat(const Bureaucrat& a);			// 복사생성자
	Bureaucrat& operator=(const Bureaucrat& a);	// 대입연산자
	~Bureaucrat();								// 소멸자

	const std::string getName(void) const;
	const int getGrade(void) const;
	void IncrementGrade(int _grade);
	void DecrementGrade(int _grade);


};
#endif


/*
Remember. Since grade 1 is the highest one and 150 the lowest,
incrementing a grade 3 should give a grade 2 to the bureaucrat.

이게 무슨말이야...?
*/

/*
int main(){
    vector<int> v{1, 2, 3, 4};
    int num;
    cin >> num;

    try{
        cout << v.at(num) << endl;

    }
    catch(exception& e){
        cout << e.what() << endl;
        cout << "인덱스 오류가 발생!" << endl;
    }

    cout << "[program is still running!]" << endl;

    return 0;
}
*/