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
    	//std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	}
}

static void	vRecursion(vectorPair& pairs)
{
	if (pairs.size() < 2)
		return;
	vectorPair::iterator	last = pairs.end() - 1;
	std::pair<int, int>		tmp = *last;
	vectorPair::iterator	insert_pos = pairs.begin();
	while (insert_pos != last && insert_pos->first <= last->first)
		++insert_pos;
	if (insert_pos != last)
	{
		pairs.erase(last);
		pairs.insert(insert_pos, tmp);
		vRecursion(pairs);
	}
}

void	PmergeMe::pmergeMeVector()
{
	vectorPair	pairs;

	vPairwiseComparison(this->_vec, pairs);
	vRecursion(pairs);
	std::cout << "\n-------------------------------\n ORDERED PAIRS\n";
	for (vectorPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
    	std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	}
}

static void	lPairwiseComparison(std::list<int> list, listPair& pairs)
{
	if (list.size() % 2 != 0)
        list.pop_back();
	for (std::list<int>::iterator it = list.begin(); std::distance(it, list.end()); it++)
		pairs.push_back(std::make_pair(*it, *(++it)));
	for (listPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);
    	//std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	}
}

static void	lRecursion(listPair& pairs)
{
	if (pairs.size() < 2)
		return;
	listPair::iterator	last = pairs.end();
	--last;
	listPair::iterator	insert_pos = pairs.begin();
	while (insert_pos != last && insert_pos->first <= last->first)
		++insert_pos;
	if (insert_pos != last)
	{
		pairs.splice(insert_pos, pairs, last);
		lRecursion(pairs);
	}
}

void	PmergeMe::pmergeMeList()
{
	listPair	pairs;

	lPairwiseComparison(this->_list, pairs);
	lRecursion(pairs);
	std::cout << "\n-------------------------------\n ORDERED PAIRS\n";
	for (listPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
    	std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	}
}
