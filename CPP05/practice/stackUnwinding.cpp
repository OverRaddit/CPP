#include <iostream>

using namespace std;

void SimpleFuncOne(void) throw ();
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main()
{
	// 예외처리를 안하면 terminate함수가 호출된다.
	//SimpleFuncOne();

	try
	{
		SimpleFuncOne();
	}
	catch(char expn)
	{
		cout << "예외코드 : " << expn << endl;
	}
	catch(int expn)
	{
		cout << "예외코드 : " << expn << endl;
	}

	cout << "Check End" << endl;
	return 0;
}

void SimpleFuncOne(void) throw (int)
{
	cout << "One" << endl;
	SimpleFuncTwo();
}
void SimpleFuncTwo(void)
{
	cout << "Two" << endl;
	SimpleFuncThree();
}
void SimpleFuncThree(void)
{
	cout << "Three" << endl;
	throw -1;
}

