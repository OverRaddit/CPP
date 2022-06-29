#include "Identify.hpp"

class D{

};

int main(void)
{
	Base *ptr = generate();
	//identify(ptr);	// use by ptr
	identify(*ptr);	// use by ref
	std::cout << std::endl;

	Base *ptr2 = new C();
	//identify(ptr2);	// use by ptr
	identify(*ptr2);	// use by ref
	std::cout << std::endl;

	delete ptr;
	delete ptr2;
}
