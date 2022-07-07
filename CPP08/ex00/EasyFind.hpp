#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>
# include <iostream>
# include <vector>
// 편의상 여기서 예외클래스를 정의했지만 다른 파일로 옮겨야 한다.
class NoElementException : public std::exception
{
private:
public:
	virtual ~NoElementException() throw(){};
	virtual const char* what() const throw(){return "NoElementException";};
};

template <class T>
typename T::iterator easyfind(T& v, int value)
{
	typename T::iterator iter;
	// v = vector<int>
	// 검색결과 없을경우 throw
	iter = std::find(v.begin(), v.end(), value);
	if (iter == v.end())
		throw std::exception();
	else
		return iter;
	// std::cout << "Find item : " << *iter << std::endl;
}

#endif

/*
T 는  정정수  컨테이너
이 함수는 첫번째 파라미터에서 두번째 파라미터의 occurence를 찾아야 한다.
occurence는 문맥상 원소의 개수? 인덱스?를 뜻하는 것 같다.
T에서 value를 찾되 첫번째 발견된 것을 리턴하라는 것 같다.

C++ 컨테이너에서는 예외를 어떻게 던지고 처리할까?

테스트 코드를 직접 작성하자.

(i) associative containers를 만질 필요가 없다.
*/