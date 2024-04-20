#include "Serializer.hpp"

int main(void)
{
	Data	data = {1, "Ola"};
	Data*	ptr = &data;
	Data*	ptr2;

	ptr2 = Serializer::deserialize(Serializer::serialize(ptr));
	std::cout << "Pointer 1: " << ptr << "\n";
	std::cout << "Pointer 2: " << ptr2 << "\n\n";

	if (ptr == ptr2)
	{
		std::cout << "The pointers have the same data\n\n";
		std::cout << "Pointer 1 Data---------\nint: " << ptr->value << "\nstr: " << ptr->str << "\n\n";
		std::cout << "Pointer 2 Data---------\nint: " << ptr2->value << "\nstr: " << ptr2->str << "\n";
	}
	else
	{
		std::cout << "The pointers do not have the same data\n\n";
		std::cout << "Pointer 1 Data---------\nint: " << ptr->value << "\nstr: " << ptr->str << "\n\n";
		std::cout << "Pointer 2 Data---------\nint: " << ptr2->value << "\nstr: " << ptr2->str << "\n";
	}
	return 0;
}
