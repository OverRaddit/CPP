#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <exception>
# include <algorithm>
# include <iostream>
# include <vector>
# include <stack>
# include <list>

template <class T>
class MutantStack: public std::stack<T, std::list<T> >
//class MutantStack: public std::list<T>
{
private:
public:
	// typedef typename std::list<T>::iterator iterator;
	// typedef typename std::list<T>::reverse_iterator reverse_iterator;

	typedef typename std::stack<T, std::list<T> >::container_type::iterator iterator;
	typedef typename std::stack<T, std::list<T> >::container_type::reverse_iterator reverse_iterator;

//=============================================================================
//	Orthodox Canonical Form [2]
//=============================================================================
	MutantStack()
	{
		// 부모 생성자 with list
	}
	MutantStack(const MutantStack& s)
	{
		// ?
		*this = s;
	}
	const MutantStack& operator=(const MutantStack& s)
	{
		(void)s;
		// ...?
	}
	~MutantStack(){};
//=============================================================================
//	Function
//=============================================================================

	iterator begin(void) {return this->c.begin();}
	iterator end(void){return this->c.end();};
	reverse_iterator rbegin(void) {return this->c.rbegin();} // [1]
	reverse_iterator rend(void){return this->c.rend();};

	// iterator with list
	// iterator begin(void) {return std::list<T>::begin();}
	// iterator end(void){return std::list<T>::end();};
	// reverse_iterator rbegin(void) { std::list<T>::rbegin();}
	// reverse_iterator rend(void){ std::list<T>::rend();};
};

#endif
