#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

class MutantStack
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(MutantStack const &copy);
		MutantStack &operator=(MutantStack const &assignment);
};

#endif
