#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <climits>	// 무슨 이유인지 이 헤더가 없어도 INT_MAX를 쓸 수 있다.

class Span
{
private:
	std::vector<int> v;
	unsigned int size;
	bool isSort;

	Span(); // [3]
public:
//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
	Span(unsigned int N);
	Span(const Span& s);
	const Span& operator=(const Span& s);
	~Span();
//=============================================================================
//	Function
//=============================================================================
	void addNumber(int n);

	template<class T>
	void addNumbers(T& input)
	{
		if (size < v.size() + input.size())
			throw std::exception();

		v.insert(v.end(), input.begin(), input.end());
		isSort = false;
	}
	// void addNumbers(std::vector<int> &input)
	// {
	// 	//std::cout << v.size() << " " << size << " " << input.size() << std::endl;
	// 	if (size < v.size() + input.size())
	// 		throw std::exception();
	// 	v.insert(v.end(), input.begin(), input.end());
	// 	isSort = false;
	// }

	const std::vector<int>& getData(void) const;

	long long shortestSpan();
	long long longestSpan();
};

#endif
