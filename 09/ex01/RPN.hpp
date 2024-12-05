#ifndef RPN_HPP
# define RPN_HPP

#include <exception>
#include <string>
#include <stack>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &assignment);

		int		evaluate(std::string expr);

		static std::exception	invalidExpr();
		static std::exception	outOfRange();
	private:
		std::stack<int>	_le_stack;
};

#endif
