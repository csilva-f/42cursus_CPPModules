#include "PmergeMe.hpp"
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vec): _vec(vec), _list(vec.begin(), vec.end()) {}

PmergeMe::PmergeMe(const PmergeMe& other): _vec(other._vec), _fvec(other._fvec), _list(other._list), _flist(other._flist) {}

PmergeMe	&PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_list = other._list;
		this->_fvec = other._fvec;
		this->_flist = other._flist;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

static void	vPairwiseComparison(std::vector<int> vec, vectorPair& pairs)
{
	if (vec.size() < 2)
		return;
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

static bool isVectorOrdered(const vectorPair& pairs)
{
    for (size_t i = 0; i < pairs.size() - 1; ++i)
        if (pairs[i].first > pairs[i + 1].first)
            return false;
    return true;
}

static void	vRecursion(vectorPair& pairs, vectorPair::iterator last)
{
	if (pairs.size() < 2)
		return;
	std::pair<int, int>		tmp = *last;
	vectorPair::iterator	insert_pos = pairs.begin();
	while (insert_pos != last && insert_pos->first <= tmp.first)
		++insert_pos;
	if (insert_pos != last)
	{
		pairs.erase(last);
		pairs.insert(insert_pos, tmp);
		/*for (vectorPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
    		std::pair<int, int>& pair = *it;
    		std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
		}
		vRecursion(pairs, last);*/
	}
	else if (insert_pos == last && !isVectorOrdered(pairs))
			vRecursion(pairs, --last);
}

void	PmergeMe::pmergeMeVector()
{
	vectorPair	pairs;

	vPairwiseComparison(this->_vec, pairs);
	vRecursion(pairs, pairs.end() - 1);
	/*std::cout << "\n-------------------------------\n ORDERED PAIRS\n";
	for (vectorPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
    	std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	}*/
}

static void	lPairwiseComparison(std::list<int> list, listPair& pairs)
{
	if (list.size() < 2)
		return;
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

static bool isListOrdered(const listPair& pairs)
{
	listPair::const_iterator	it = pairs.begin();
	if (it == pairs.end())
        return true;
	listPair::const_iterator	next = it;
    ++next;
    while (next != pairs.end())
	{
        if (it->first > next->first)
            return false;
        ++it;
        ++next;
    }
    return true;
}

/*static void	vRecursion(vectorPair& pairs, vectorPair::iterator last)
{
	if (pairs.size() < 2)
		return;
	std::pair<int, int>		tmp = *last;
	vectorPair::iterator	insert_pos = pairs.begin();
	while (insert_pos != last && insert_pos->first <= tmp.first)
		++insert_pos;
	if (insert_pos != last)
	{
		pairs.erase(last);
		pairs.insert(insert_pos, tmp);
		for (vectorPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
    		std::pair<int, int>& pair = *it;
    		std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
		}
		vRecursion(pairs, last);
	}
	else if (insert_pos == last && !isVectorOrdered(pairs))
			vRecursion(pairs, --last);
}*/

static void	lRecursion(listPair& pairs, listPair::iterator last, int rem, int iter = 0)
{
	if (pairs.size() < 2)
		return;
	listPair::iterator	insert_pos = pairs.begin();
	while (insert_pos != last && insert_pos->first <= last->first)
		++insert_pos;
	std::cout << "i: " << iter << " begin(" << pairs.begin()->first << ", " << pairs.begin()->second << ") ";
	std::cout << "last(" << last->first << ", " << last->second << ") ";
	std::cout << "ip(" << insert_pos->first << ", " << insert_pos->second << ")\n";
	if (insert_pos != last)
	{
		pairs.splice(insert_pos, pairs, last);
		for (listPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
    		std::pair<int, int>& pair = *it;
    		std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
		}
		last = pairs.end();
		last--;
		for (int i = 0; i < rem; i++)
			--last;
		lRecursion(pairs, last, rem, iter + 1);
	}
	else if (insert_pos == last && !isListOrdered(pairs))
	{
		--last;
		lRecursion(pairs, last, rem + 1, iter + 1);
	}
}

void	PmergeMe::pmergeMeList()
{
	listPair	pairs;

	lPairwiseComparison(this->_list, pairs);
	listPair::iterator	last = pairs.end();
	--last;
	lRecursion(pairs, last, 0);
	std::cout << "\n-------------------------------\n ORDERED PAIRS\n";
	for (listPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
    	std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	}
}
