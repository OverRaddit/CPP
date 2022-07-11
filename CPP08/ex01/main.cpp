#include "Span.hpp"
// 기본기능 검사
void test_sample(){
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

// 한번에 여러 숫자를 입력하는 멤버함수 기능검사
void test_addNumbers(){
	Span sp = Span(105);
	//std::vector<int> arr;
	std::list<int> arr;

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	for(int i=0;i<100;i++)
		arr.push_back(i);

	sp.addNumbers(arr);

	std::cout << "sp's size = " << sp.getData().size() << std::endl;
	for(int i=0;i<105;i++)
		std::cout << sp.getData()[i] << "\n";
}

// 허용된 용량을 초과할때 예외처리 검사
void test_StoreException(){
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(777);	// can't store! exception
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "can't store!" << std::endl;
	}

	Span sp2 = Span(5);
	std::vector<int> arr;

	sp2.addNumber(6);
	for(int i=0;i<5;i++)
		arr.push_back(i);

	try
	{
		// capacity(5) : size(1) + arrsize(5) => exception!
		sp2.addNumbers(arr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "can't store!" << std::endl;
	}
}


void test_zero(){
	Span sp = Span(0);
	std::cout << "succeed to make 0 Span\n";

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void test_spanException(){
	Span sp0 = Span(0);
	Span sp1 = Span(1);
	Span sp2 = Span(2);

	sp1.addNumber(6);

	sp2.addNumber(3);
	sp2.addNumber(17);

	try
	{
		std::cout << sp0.shortestSpan() << std::endl;
		std::cout << sp0.longestSpan() << std::endl;

		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "you can't use span func when size < 2" << std::endl;
	}


}

void test_10thousand()
{
	Span sp = Span(10000);
	std::vector<int> arr;

	for(int i=0;i<10000;i++)
		arr.push_back(i);

	sp.addNumbers(arr);

	std::cout << "sp's size = " << sp.getData().size() << std::endl;
	for(int i=0;i<10000;i++)
		std::cout << sp.getData()[i] << "\n";
}

int main() {

	test_sample();
	test_addNumbers();

	//Error case
	test_StoreException();
	test_zero();
	test_spanException();
	test_10thousand();
	return 0;
}
