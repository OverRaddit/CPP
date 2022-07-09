#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <algorithm>
# include <iostream>
# include <vector>
# include <climits>	// 무슨 이유인지 이 헤더가 없어도 INT_MAX를 쓸 수 있다.

class Span
{
private:
	std::vector<int> v;
	unsigned int size;
	bool isSort;
public:
// orthodox canonical form
	Span() : size(0), isSort(false)
	{

	}
	Span(unsigned int N) : size(N), isSort(false)
	{
	}
	Span(const Span& s)
	{
		*this = s;
	}
	const Span& operator=(const Span& s)
	{
		if (this == &s)
			return *this;
		v = s.v;	// stl vector가 이미 내부적으로 깊은복사가 구현되어 있다
		return *this;
	}
	~Span(){}

// function
	void addNumber(int n)
	{
		if (v.size() >= size)
			throw std::exception();
		//std::cout << "v.size() = " << v.size() << std::endl;
		v.push_back(n);
		isSort = false;
	}
	int shortestSpan()
	{
		int ret = INT_MAX;	// [1] climits 헤더 추가 안했는데 왜 돌아가지..?
		if (v.size() <= 1)
			throw std::exception();
		if (!isSort)
			sort(v.begin(), v.end());

		for(size_t i=0; i < v.size() - 1; i++)	// [2] v.size()의 반환값은 size_t
			if (v[i + 1] - v[i] < ret)
				ret = v[i + 1] - v[i];

		return ret;
	}
	int longestSpan()
	{
		if (v.size() <= 1)
			throw std::exception();
		if (!isSort)
			sort(v.begin(), v.end());

		return v[v.size() - 1] - v[0];
	}
};

#endif
