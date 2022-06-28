#include "Identify.hpp"

static Base* getA();
static Base* getB();
static Base* getC();

Base* generate(void)
{
	typedef Base* (*ptr)(void);
	ptr getObject[3] = {&getA, &getB, &getC};
	std::srand(std::time(nullptr));

	return getObject[ std::rand() % 3 ]();
}
void identify(Base* p)
{

}
void identify(Base& p)
{

}

static Base* getA(){return new A();}
static Base* getB(){return new B();}
static Base* getC(){return new C();}