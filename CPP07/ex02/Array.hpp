#pragma once

# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>

template <typename T > class Array
{
private:
	T*				_arr;
	unsigned int	_size;

public:
	Array(): _arr(new T[0]), _size(0) {}
	Array(unsigned int n): _arr(new T[n]), _size(n) {}
	Array(const Array& other): _arr(new T[other._size]), _size(other._size)
	{
		for (unsigned int i = 0; i < other.size(); i++)
			this->_arr[i] = other._arr[i];
	}
	Array &operator=(const Array& other)
	{
		if (this != &other)
		{
			if (this->_arr)
				delete [] this->_arr;
			this->_arr = new T[other._size];
			this->_size = other._size;
			for (unsigned int i = 0; i < other.size(); i++)
				this->_arr[i] = other._arr[i];
		}
		return *this;
	}
	T &operator[](unsigned int ind)
	{
		if (ind >= this->_size)
			throw IndexOutOfBounds();
		return (this->_arr[ind]);
	}
	class IndexOutOfBounds: public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Out of bounds index\n");
			}
	};
	unsigned int	size() const
	{
		return this->_size;
	}
	~Array() { delete [] this->_arr; }
};
