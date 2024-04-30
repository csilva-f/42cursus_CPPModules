#pragma once

# include <exception>
# include <iostream>
# include <algorithm>
# include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), n);
	// std::find: returns an iterator to the first occurence of the specified element in the sequence
	if (iter == container.end())
		throw std::exception();
	return iter;
}
