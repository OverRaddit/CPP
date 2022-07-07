#ifndef EASYFIND_HPP
# define EASYFIND_HPP

/*
Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.

If no occurrence is found, you can either throw an exception or return an error value of your choice.

If you need some inspiration, analyze how standard containers behave.

Of course, implement and turn in your own tests to ensure everything works as ex- pected.
*/

template <class T> void easyfind(T &x, int n)
{
	std::cout << "==print Function==" << std::endl;
	std::cout << "\"" << x << "\"" << std::endl;
	std::cout << "==================" << std::endl;
}

#endif