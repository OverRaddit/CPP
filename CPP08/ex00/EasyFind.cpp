#include "EasyFind.hpp"

NoElementException::~NoElementException() throw(){};
const char* NoElementException::what() const throw(){return "NoElementException";};