#include <iostream>
#include "Data.hpp"

int main()
{
	Data *original = new Data("gshim", 100, true);
	std::cout << *original << std::endl;

	// Data* => uintptr_t
	uintptr_t broker = serialize(original);

	// uintptr_t => Data*
	Data *clone = deserialize(broker);
	std::cout << *clone << std::endl;
	delete original;
}