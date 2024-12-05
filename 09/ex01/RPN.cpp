#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <string>

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &copy)
{
	*this = copy;
}

RPN	&RPN::operator=(RPN const &assignment)
{
	(void)assignment;
	return *this;
}

void	operands_exec(char expr, std::stack<int> &_le_stack)
{
	int	tmp;

	switch (expr)
	{
		case '+':
			tmp = _le_stack.top();
			_le_stack.pop();
			_le_stack.top() += tmp;
		break;
		case '-':
			tmp = _le_stack.top();
			_le_stack.pop();
			_le_stack.top() -= tmp;
		break;
		case '*':
			tmp = _le_stack.top();
			_le_stack.pop();
			_le_stack.top() *= tmp;
		break;
		case '/':
			tmp = _le_stack.top();
			if (tmp == 0) throw RPN::invalidExpr();
			_le_stack.pop();
			_le_stack.top() /= tmp;
		break;
		default: throw RPN::invalidExpr(); break;
	}
}

int	RPN::evaluate(std::string expr)
{
	int	tmp;
	for (size_t i = 0; i < expr.length(); i++)
	{
		if (expr[i] == ' ')
			continue ;
		if (std::isdigit(expr[i]))
		{
			size_t	number_length = std::string(expr.c_str() + i).find(" ");
			tmp = std::strtol(expr.substr(i, number_length).c_str(), NULL, 10);
			if (tmp < 0 || tmp > 9)
				throw RPN::outOfRange();
			_le_stack.push(tmp);
		}
		else if (_le_stack.size() >= 2)
			operands_exec(expr[i], _le_stack);
		else
			throw RPN::invalidExpr();
	}

	if (_le_stack.size() > 1)
		throw RPN::invalidExpr();
	return _le_stack.top();
}

std::exception	RPN::invalidExpr()
{
	std::invalid_argument	exception("Invalid expression.");
	throw exception;
}

std::exception	RPN::outOfRange()
{
	std::invalid_argument	exception("Number out of range.");
	throw exception;
}
