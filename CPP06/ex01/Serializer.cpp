#include "Serializer.hpp"

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

Serializer	&Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}
