#include "../include/Serializer.hpp"
#include <iostream>
#include <ostream>

int main()
{
	Data	data;
	std::string	day_of_week[7] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};

	// Set data
	data.key = "days";
	data.value = reinterpret_cast<uintptr_t>(day_of_week);
	std::cout << "Unserialized pointer (runtime addr): " << &data <<std::endl;

	// Serialize data (pack pointer as serial value)
	uintptr_t serial_data_ptr = Serializer::serialize(&data);
	std::cout << "Serialized pointer (addr packet): " << serial_data_ptr <<std::endl;
	
	// Working with serialized data, bit manipulation blah blah...
	std::cout << "Other code go brrrrrrr...." << std::endl;

	// Deserialize (unpack the serial value back to pointer)
	Data *recievd = Serializer::deserialize(serial_data_ptr);
	std::cout << "Deserialized pointer (deconstructed addr): " << recievd <<std::endl;
	std::cout << "Key: " << recievd->key <<std::endl;
	std::cout << "Values: " << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << i
				  << ": "
				  << reinterpret_cast<std::string*>(recievd->value)[i] <<std::endl;
	return 0;
}
