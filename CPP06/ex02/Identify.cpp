#include "Identify.hpp"

Base* getA();
Base* getB();
Base* getC();

Base* generate(void)
{
	typedef Base* (*ptr)(void);
	ptr getObject[3] = {&getA, &getB, &getC};
	std::srand(std::time(nullptr));

	return getObject[ std::rand() % 3 ]();
}
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "p: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "p: C" << std::endl;
	else
		std::cout << "Something Wrong..." << std::endl;
}

int casting(Base& p, const std::string& name)
{
	std::cout << "[casting fun] " << name << std::endl;
	try
	{
		if (name == "A")
			(void)dynamic_cast<A&>(p);
		else if (name == "B")
			(void)dynamic_cast<B&>(p);
		else if (name == "C")
			(void)dynamic_cast<C&>(p);
		else
			return 1;
		std::cout << "p: " << name << std::endl;
	}
	catch(const std::exception& e)
	{
		#ifdef DEBUG
		std::cerr << e.what() << '\n';
		#endif
		return 1;
	}
	return 0;
}

void identify(Base& p)
{
	if (!casting(p, "A") || !casting(p, "B") || !casting(p, "C"))
		std::cout << "Identify Success" << std::endl;
}

Base* getA(){return new A();}
Base* getB(){return new B();}
Base* getC(){return new C();}
