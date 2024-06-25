#include "../include/Span.hpp"
#include <exception>
#include <iostream>

int main ()
{
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		// sp.fill();

		std::cout << "shortest span: " << sp.shortestSpan() << std::endl; // 11 - 9 = 2
		std::cout << "longest span: " << sp.longestSpan() << std::endl; // 17 - 3 = 14
	} catch(std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
