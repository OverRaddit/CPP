#include <iostream>

using namespace std;

int main(){
	int N;
	while(1)
	{
		cin >> N;
		if (cin.fail())
		{
			cout << "error!" << endl;
			cin.clear();
		}
		cout << N << endl;
	}
}