#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base* getA();
Base* getB();
Base* getC();

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif