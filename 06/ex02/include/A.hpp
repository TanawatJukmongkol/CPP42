#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class A: public Base
{
	public:
		A();
		~A();
		A(A const &copy);
		A &operator=(A const &assignment);
};

#endif
