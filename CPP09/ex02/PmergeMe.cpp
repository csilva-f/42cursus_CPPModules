#include "PmergeMe.hpp"

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
		vRecursion(pairs, last);
	}
	else if (insert_pos == last && !isVectorOrdered(pairs))
		vRecursion(pairs, --last);
}

static std::vector<int>	getJacobsthalIntervalVector(int n)
{
	int 				i = 0;
	int					j = 1;
	int					p = j - i;
	std::vector<int>	v;
	v.push_back(p);
	while (n > 0)
	{
		int	t = j;
		j = t + 2 * i;
		i = t;
		p = j - i;
		n -= p;
		if (p > 0)
			v.push_back(p);
	}
	return v;
}

void	PmergeMe::pmergeMeVector()
{
	vectorPair	pairs;

	vPairwiseComparison(this->_vec, pairs);
	vRecursion(pairs, pairs.end() - 1);
	int	n = pairs.size() - 1;
	if (this->_vec.size() % 2 != 0)
		n += 1;
	std::vector<int>	v = getJacobsthalIntervalVector(n);
	for (vectorPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
		this->_fvec.push_back(it->first);
	n = 0;
	for (std::vector<int>::size_type i = 0; i < v.size(); i++)
	{
		n += v[i];
		vectorPair::iterator it = pairs.begin();
		int	j;
		for (j = n - 1; j > 0 && it != (pairs.end() - 1); j--)
			++it;
		if (j > 0 && this->_vec.size() % 2 != 0)
		{
			bool	p = false;
			for (std::vector<int>::size_type z = 0; z < this->_fvec.size(); z++)
			{
				if (this->_fvec[z] > this->_vec[this->_vec.size() - 1])
				{
					this->_fvec.insert(this->_fvec.begin() + z, this->_vec[this->_vec.size() - 1]);
					p = true;
					break;
				}
			}
			if (!p)
				this->_fvec.push_back(this->_vec[this->_vec.size() - 1]);
		}
		for (int x = 0; x < v[i] - j; x++)
		{
			for (std::vector<int>::size_type z = 0; z < this->_fvec.size(); z++)
			{
				if (this->_fvec[z] > it->second)
				{
					this->_fvec.insert(this->_fvec.begin() + z, it->second);
					break;
				}
			}
			if (it != pairs.begin())
				--it;
		}
	}
	std::cout << "After: ";
	for (std::vector<int>::size_type i = 0; i < this->_fvec.size(); ++i)
        std::cout << this->_fvec[i] << " ";
	std::cout << std::endl;
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

static void	lRecursion(listPair& pairs, listPair::iterator last, int rem, int iter = 0)
{
	if (pairs.size() < 2)
		return;
	listPair::iterator	insert_pos = pairs.begin();
	while (insert_pos != last && insert_pos->first <= last->first)
		++insert_pos;
	if (insert_pos != last)
	{
		pairs.splice(insert_pos, pairs, last);
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

static std::list<int>	getJacobsthalIntervalList(int n)
{
	int 			i = 0;
	int				j = 1;
	int				p = j - i;
	std::list<int>	l;
	l.push_back(p);
	while (n > 0)
	{
		int	t = j;
		j = t + 2 * i;
		i = t;
		p = j - i;
		n -= p;
		if (p > 0)
			l.push_back(p);
	}
	return l;
}

void	PmergeMe::pmergeMeList()
{
	listPair	pairs;

	lPairwiseComparison(this->_list, pairs);
	listPair::iterator	last = pairs.end();
	--last;
	lRecursion(pairs, last, 0);
	int	n = pairs.size() - 1;
	if (this->_list.size() % 2 != 0)
		n += 1;
	std::list<int>	l = getJacobsthalIntervalList(n);
	for (listPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
        this->_flist.push_back(it->first);
	n = 0;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
        n += *it;
        listPair::iterator	itPair = pairs.begin();
        int j;
        for (j = n - 1; j > 0 && itPair != --pairs.end(); --j)
            ++itPair;
        if (j > 0 && this->_list.size() % 2 != 0)
		{
            bool p = false;
            for (std::list<int>::iterator z = this->_flist.begin(); z != this->_flist.end(); ++z)
			{
                if (*z > this->_list.back())
				{
                    this->_flist.insert(z, this->_list.back());
                    p = true;
                    break;
                }
            }
            if (!p)
                this->_flist.push_back(this->_list.back());
        }
        for (int x = 0; x < *it - j; ++x)
		{
            std::pair<int, int>& pair = *itPair;
            for (std::list<int>::iterator z = this->_flist.begin(); z != this->_flist.end(); ++z)
			{
                if (*z > pair.second)
				{
                    this->_flist.insert(z, pair.second);
                    break;
                }
            }
            if (itPair != pairs.begin())
                --itPair;
        }
    }
    /*std::cout << "After L: ";
    for (std::list<int>::iterator it = this->_flist.begin(); it != this->_flist.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;*/
}

/*std::cout << "\n-------------------------------\n ORDERED PAIRS\n";
	for (listPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
    	std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
}*/

/*void	PmergeMe::pmergeMeVector()
{
	vectorPair	pairs;

	vPairwiseComparison(this->_vec, pairs);
	vRecursion(pairs, pairs.end() - 1);
	std::cout << "\n-------------------------------\n ORDERED PAIRS\n";
	for (vectorPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
    	std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	}
	int	n = pairs.size() - 1;
	if (this->_vec.size() % 2 != 0)
		n += 1;
	std::cout << "\nvec size: " << this->_vec.size() << "\npairs nbr: " << pairs.size() << "\n";
	std::cout << "n: " << n << "\nJ nbr: ";
	std::vector<int>	v = getJacobsthalIntervalVector(n);
	std::cout << "\nJacobsthal numbers: ";
	for (std::vector<int>::size_type i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
	std::cout << "\n";
	for (vectorPair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
    	std::pair<int, int>& pair = *it;
		this->_fvec.push_back(pair.first);
	}
	for (std::vector<int>::size_type i = 0; i < this->_fvec.size(); ++i)
        std::cout << this->_fvec[i] << " ";
	std::cout << "\n";
	n = 0;
	for (std::vector<int>::size_type i = 0; i < v.size(); i++)
	{
		n += v[i];
		std::cout << "n: " << n << "\n";
		vectorPair::iterator it = pairs.begin();
		int	j;
		for (j = n - 1; j > 0 && it != (pairs.end() - 1); j--)
		{
	   		std::cout << "(" << it->first << ", " << it->second << ")\n";
			++it;
		}
		std::pair<int, int>& pair = *it;
		std::cout << "(" << pair.first << ", " << pair.second << ")\n";
		if (j > 0 && this->_vec.size() % 2 != 0)
		{
			int	p = 0;
			for (std::vector<int>::size_type z = 0; z < this->_fvec.size(); z++)
			{
				if (this->_fvec[z] > this->_vec[this->_vec.size() - 1])
				{
					this->_fvec.insert(this->_fvec.begin() + z, this->_vec[this->_vec.size() - 1]);
					p = 1;
					break;
				}
			}
			if (!p)
				this->_fvec.push_back(this->_vec[this->_vec.size() - 1]);
		}
		std::cout << "j: " << j << "\n";
		for (int x = 0; x < v[i] - j; x++)
		{
			std::pair<int, int>& pair = *it;
			for (std::vector<int>::size_type z = 0; z < this->_fvec.size(); z++)
			{
				if (this->_fvec[z] > pair.second)
				{
					this->_fvec.insert(this->_fvec.begin() + z, pair.second);
					break;
				}
			}
			if (it != pairs.begin())
				--it;
			std::cout << "fvec: ";
			for (std::vector<int>::size_type i = 0; i < this->_fvec.size(); ++i)
        		std::cout << this->_fvec[i] << " ";
			std::cout << "\n";
		}
	}
	std::cout << "After: ";
	for (std::vector<int>::size_type i = 0; i < this->_fvec.size(); ++i)
        std::cout << this->_fvec[i] << " ";
	std::cout << std::endl;
}*/
