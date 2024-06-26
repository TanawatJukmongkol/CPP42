#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "DataStruct.hpp"

class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(Serializer const &copy);
		Serializer &operator=(Serializer const &assignment);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
