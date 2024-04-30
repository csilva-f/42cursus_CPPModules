#pragma once

# include <iostream>
# include <limits>
# include <list>
# include <vector>
# include <algorithm>
# include <utility>

typedef std::vector<std::pair<int, int> >	vectorPair;
typedef	std::list<std::pair<int, int> >		listPair;

class PmergeMe
{
public:
	std::vector<int>	_vec;
	std::list<int>		_list;

	PmergeMe();
	PmergeMe(std::vector<int> vec);
	PmergeMe(const PmergeMe& other);
	PmergeMe	&operator=(const PmergeMe& other);
	~PmergeMe();

	template <typename Container>
    void printContainer(const Container& c) const;

	void	pmergeMeVector();
	void	pmergeMeList();
};

template <typename T>
void	PmergeMe::printContainer(const T& c) const
{
    typename T::const_iterator it;
	for (it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
