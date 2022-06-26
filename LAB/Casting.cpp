#include <iostream>

using namespace std;

// class A
// {
// private:
// 	/* data */
// public:
// 	A(/* args */);
// 	~A();
// 	virtual void VirtualTestA(){}
// 	void TestA(){}
// };

// A::A(/* args */)
// {
// }

// A::~A()
// {
// }

// class B : public A
// {
// private:
// 	/* data */
// public:
// 	B(/* args */);
// 	~B();

// 	void TestA(){}
// };

// B::B(/* args */)
// {
// }

// B::~B()
// {
// }



// int main()
// {
// 	//A *parent = new A();
// 	A *parent = new B();
// 	B *child = new B();
// 	B *c;

// 	dynamic_cast<A*>(c);	// 자식 -> 부모로만 갈 수 있구만.
// 	c = dynamic_cast<B*>(parent);	// 부모 -> 자식은 오류발생
// }

int main(){
	float a = atof("11.2s3 x  ");
	printf("%f\n", a);
}