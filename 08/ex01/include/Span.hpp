#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstddef>
#include <exception>
#include <vector>

class Span
{
	public:
		Span(unsigned int N);
		~Span();
		Span(Span const &copy);
		Span &operator=(Span const &assignment);

		// Pushes the span to a fixed size vector.
		void addNumber(int number);

		// Gets the shortest span (minimum diffrence of two number).
		int shortestSpan();
		int longestSpan();

		// Fill
		void fill();

		static std::exception	AlreadyFilled();
		static std::exception	IsEmpty();
		static std::exception	LengthIsOne();

	private:
		const unsigned int	_size;
		size_t				_prev_size; // For detect cach miss
		std::vector<int>	_vec;
		int					_nbr; // Cache smallest span
};

#endif
