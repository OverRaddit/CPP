#include "MutantStack.hpp"

void test_sample()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, std::list<int> > s(mstack);
}

void test_orthodox()
{
	// MutantStack<int> mstack;
	// MutantStack<int> mstack(int, std::list<int>);
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int, std::list<int> > s(mstack);
	std::cout << "Copy Construction Stack will pop" << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::stack<int> assign;
	assign = mstack;
	std::cout << "Assignment Stack will pop" << std::endl;
	while (!assign.empty())
	{
		std::cout << assign.top() << std::endl;
		assign.pop();
	}
}

// void test_reverse_iterator()
// {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);

// 	MutantStack<int>::reverse_iterator it = mstack.rbegin();
// 	MutantStack<int>::reverse_iterator ite = mstack.rend();

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// }

// void test_list()
// {
// 	MutantStack<int> mstack;

// 	mstack.push_back(5);
// 	mstack.push_back(17);

// 	std::cout << mstack.back() << std::endl;

// 	mstack.pop_back();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::list<int> s(mstack);
// }


int main()
{
	test_sample();
	// test_orthodox();
	// test_reverse_iterator();
	//test_list();

	//std::stack<int, std::list<int> > vlist;

	return 0;
}
