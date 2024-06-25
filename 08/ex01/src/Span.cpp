#include "../include/Span.hpp"
#include <algorithm>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N): _size(N)
{
	_vec.reserve(N);
	_prev_size = 0;
	std::cout << "Span created" << std::endl;
}

Span::~Span()
{
	std::cout << "Span destroyed" << std::endl;
}

Span::Span(Span const &copy): _size(copy._size)
{
	*this = copy;
}

Span	&Span::operator=(Span const &assignment)
{
	(void)assignment;
	return *this;
}

void	Span::addNumber(int number)
{
	if (_vec.size() == _size)
		throw Span::AlreadyFilled();
	_vec.push_back(number);
}

void	Span::fill()
{
	if (_vec.size() == _size)
		throw Span::AlreadyFilled();
	srand(time(0));
	// Fill the vector at the end until there's no space left.
	for (std::vector<int>::iterator i = _vec.begin() + _vec.size(); _vec.size() < _size; ++i)
		_vec.push_back(1 + rand() % _size);
}

int Span::shortestSpan()
{
	size_t	size = _vec.size();
	
	// Size too small (nested in one if statement, to reduce overhead)
	if (size < 2)
	{
		if (size == 0)
			throw Span::IsEmpty();
		if (size == 1)
			throw Span::LengthIsOne();
	}
	// Detect cache hit
	if (size == _prev_size)
		return _nbr;
	// Sort vector
	_prev_size = size;
	std::sort(_vec.begin(), _vec.end(), std::less<int>());
	// Get least span
	_nbr = INT_MAX;
	for (std::vector<int>::iterator i = _vec.begin() + 1; i != _vec.end(); ++i)
	{
		int current = *i - *(i - 1); // current_indx - previous_indx
		if (current < _nbr && current != 0) // Look for shorter span (de-duplicated numbers)
			_nbr = current;
	}
	return _nbr;
}

int Span::longestSpan()
{
	size_t	size = _vec.size();
	
	// Size too small (nested in one if statement, to reduce overhead)
	if (size < 2)
	{
		if (size == 0)
			throw Span::IsEmpty();
		if (size == 1)
			throw Span::LengthIsOne();
	}
	// Detect cache hit
	if (size == _prev_size)
		return _vec[_prev_size - 1] - _vec[0]; // last - first
	// Sort vector
	_prev_size = size;
	std::sort(_vec.begin(), _vec.end(), std::less<int>());
	return _vec[_prev_size - 1] - _vec[0];
}

std::exception	Span::AlreadyFilled()
{
	std::runtime_error exception("Span already filled.");
	throw exception;
}

std::exception	Span::IsEmpty()
{
	std::runtime_error exception("Span is empty. Cannot perform operation.");
	throw exception;
}

std::exception	Span::LengthIsOne()
{
	std::runtime_error exception("Span has only one member. Cannot perform operation.");
	throw exception;
}
