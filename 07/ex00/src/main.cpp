#include "../include/whatever.hpp"
#include <iostream>

int main ()
{
	int a = 2;
	int b = 4;
	std::string s1 = "world";
	std::string s2 = "hello";
	std::cout << a << b << " -> ";
	::swap(a, b);
	std::cout << a << b << std::endl;
	std::cout << s1 << " " << s2 << " -> ";
	::swap(s1, s2);
	std::cout << s1 << " " << s2 << std::endl;

	std::cout << "Min nbr: " << ::min(a, b) << std::endl;
	std::cout << "Max nbr: " << ::max(a, b) << std::endl;
	std::cout << "Min str: " << ::min(s1, s2) << std::endl;
	std::cout << "Max str: " << ::max(s1, s2) << std::endl;
	return 0;
}
