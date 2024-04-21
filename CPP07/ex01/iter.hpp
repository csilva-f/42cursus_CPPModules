#pragma once

# include <iostream>
# include <cstdlib>

template <typename T> void increment(T& c)
{
	c++;
}

template <typename T> void printc(const T& c)
{
	std::cout << c;
}

template <typename T> void iter(T* array, size_t size, void (*f)(const T&))
{
	if (!array || !f)
	{
		std::cout << "Error: NULL array or function\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T> void iter(T* array, size_t size, void (*f)(T&))
{
	if (!array || !f)
	{
		std::cout << "Error: NULL array or function\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}
