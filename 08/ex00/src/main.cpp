#include "../include/easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main ()
{
	std::vector<int>	vec;
	std::list<int>		vec_lst;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(42);
	vec.push_back(50);

	vec_lst.push_back(101);
	vec_lst.push_back(123);
	vec_lst.push_back(42);
	vec_lst.push_back(555);
	vec_lst.push_back(888);
	vec_lst.push_back(7);

	std::cout << "std::vector" << std::endl;
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
		std::cout << i.base()
				  << ": "
				  << *i << std::endl;
	std::cout << "std::list" << std::endl;
	for (std::list<int>::iterator i = vec_lst.begin(); i != vec_lst.end(); ++i)
		std::cout << i._M_node
				  << ": "
				  << *i << std::endl;

	std::cout << "Find..." << std::endl;

	std::vector<int>::iterator indx = ::easyfind(vec, 42);
	std::list<int>::iterator indx_lst = ::easyfind(vec_lst, 42);

	std::cout << "[vector] "
			  << indx.base()
			  << ": "
			  << *indx << std::endl;
	std::cout << "[list]   "
			  << indx_lst._M_node
			  << ": "
			  << *indx << std::endl;
	return 0;
}
