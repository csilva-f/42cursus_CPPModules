#pragma once

# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack<T>& other);
	MutantStack	&operator=(const MutantStack<T>& other);
	~MutantStack();

	//typename std::stack<T>::container_type::iterator		begin();
	//typename std::stack<T>::container_type::iterator		end();
	// o data type e demasiado longo. Pode ser definido um alias para ele
	// ex: typedef typename std::stack<T>::container_type::iterator		alias_name;
	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	citerator;

	iterator	begin();
	iterator	end();
	citerator	cbegin() const;
	citerator	cend() const;

};

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
	std::cout << "MutantStack default constructor called\n";
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other): std::stack<T>(other)
{
	std::cout << "MutantStack copy constructor called\n";
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T>& other)
{
	std::cout << "MutantStack copy assignment operator called\n";
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called\n";
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	std::cout << "Begin of the iterator in stack called\n";
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	std::cout << "End of the iterator in stack called\n";
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::citerator	MutantStack<T>::cbegin() const
{
	std::cout << "Begin of the iterator in stack called (const)\n";
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::citerator	MutantStack<T>::cend() const
{
	std::cout << "End of the iterator in stack called (const)\n";
	return this->c.end();
}
