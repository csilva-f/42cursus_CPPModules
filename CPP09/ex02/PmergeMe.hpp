#pragma once

# include <iostream>
# include <limits>
# include <list>
# include <vector>
# include <algorithm>
# include <utility>
# include <iterator>

typedef std::vector<std::pair<int, int> >	vectorPair;
typedef	std::list<std::pair<int, int> >		listPair;

class PmergeMe
{
public:
	std::vector<int>	_vec;
	std::vector<int>	_fvec;
	std::list<int>		_list;
	std::list<int>		_flist;

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
