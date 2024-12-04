#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

#define MUT_STACK template<typename T>

template<typename T> class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(MutantStack const &copy);
		MutantStack &operator=(MutantStack const &assignment);
	private:
		std::stack<T>	__stack;
};

MUT_STACK MutantStack<T>::MutantStack()
{
	std::cout << "MutantStack created" << std::endl;
}

MutantStack::~MutantStack()
{
	std::cout << "MutantStack destroyed" << std::endl;
}

MutantStack::MutantStack(MutantStack const &copy)
{
	*this = copy;
}

MutantStack	&MutantStack::operator=(MutantStack const &assignment)
{
	(void)assignment;
	return *this;
}


#endif
