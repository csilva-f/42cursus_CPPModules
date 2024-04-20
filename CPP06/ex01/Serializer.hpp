#pragma once

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
private:
	Serializer() {}
	Serializer(const Serializer& other);
	Serializer	&operator=(const Serializer& other);
public:
	~Serializer() {}
	static uintptr_t	serialize(Data* ptr)
	{
		return reinterpret_cast<uintptr_t>(ptr);
	}

	static Data*		deserialize(uintptr_t raw)
	{
		return reinterpret_cast<Data*>(raw);
	}
};
