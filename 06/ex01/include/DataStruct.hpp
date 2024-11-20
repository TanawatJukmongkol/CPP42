#ifndef DATASTRUCT_HPP
# define DATASTRUCT_HPP

#include <stdint.h> // Had to use C header, because cstdint is used with c++ 11
#include <string>

typedef struct s_data
{
	std::string	key;
	uintptr_t	value;
} Data;

#endif
