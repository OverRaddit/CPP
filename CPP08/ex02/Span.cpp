#include "Span.hpp"

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================

Span::Span(){}
Span::Span(unsigned int N) : size(N), isSort(false)
{
}
Span::Span(const Span& s) : size(s.size), isSort(s.isSort)
{
	*this = s;
}
const Span& Span::operator=(const Span& s)
{
	if (this == &s)
		return *this;
	v = s.v;	// stl vector가 이미 내부적으로 깊은복사가 구현되어 있다
	this->size = s.size;
	this->isSort = s.isSort;
	return *this;
}
Span::~Span(){}

//=============================================================================
//	Function
//=============================================================================

void Span::addNumber(int n)
{
	if (v.size() >= size)
		throw std::exception();
	v.push_back(n);
	isSort = false;
}
const std::vector<int>& Span::getData(void) const {return v;}
long long Span::shortestSpan()
{
	long long ret = INT_MAX;	// [1] climits 헤더 추가 안했는데 왜 돌아가지..? [4]
	if (v.size() <= 1)
		throw std::exception();
	if (!isSort)
		sort(v.begin(), v.end());

	for(size_t i=0; i < v.size() - 1; i++)	// [2] v.size()의 반환값은 size_t
		if (v[i + 1] - v[i] < ret)
			ret = v[i + 1] - v[i];

	return ret;
}
long long Span::longestSpan()
{
	if (v.size() <= 1)
		throw std::exception();
	if (!isSort)
		sort(v.begin(), v.end());

	return v[v.size() - 1] - v[0];
}