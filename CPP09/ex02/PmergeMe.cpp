#include "PmergeMe.hpp"
#include <iterator>
#include <utility>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vec): _vec(vec), _list(vec.begin(), vec.end()) {}

PmergeMe::PmergeMe(const PmergeMe& other): _vec(other._vec), _list(other._list) {}

PmergeMe	&PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_list = other._list;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

static void	vPairwiseComparison(std::vector<int> vec, vectorPair& pairs)
{
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		if (i + 1 < vec.size())
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
	for (vectorPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);
    	std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	}
}

void	PmergeMe::pmergeMeVector()
{
	vectorPair	pairs;

	vPairwiseComparison(this->_vec, pairs);
}

static void	lPairwiseComparison(std::list<int> list, listPair& pairs)
{
	for (std::list<int>::iterator it = list.begin(); std::distance(it, list.end()); it++)
		pairs.push_back(std::make_pair(*it, *(++it)));
	for (listPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);
    	std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	}
}

void	PmergeMe::pmergeMeList()
{
	listPair	pairs;

	lPairwiseComparison(this->_list, pairs);
}
