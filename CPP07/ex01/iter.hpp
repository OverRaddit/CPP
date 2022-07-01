#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <class T> void print(T &x)
{
	std::cout << "==print Function==" << std::endl;
	std::cout << "\"" << x << "\"" << std::endl;
	std::cout << "==================" << std::endl;
}

template <class T> void iter(T arr[], unsigned long len, void(*f)(T&))
{
	// sizeof의 반환값. unsigned long
	for(unsigned long i=0;i<len;i++)
		f(arr[i]);
}

#endif