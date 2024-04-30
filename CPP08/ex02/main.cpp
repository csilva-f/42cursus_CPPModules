#include "MutantStack.hpp"
#include <iostream>
#include <list>

// empty: checks whether the container adaptor is empty
// pop: removes the top element
// push: inserts element at the top
// size: returns the number of elements of the stack
// top: accesses the top element

int main()
{
	{
		std::cout << "TEST 1: mutant stack\n";
		std::cout << "TEST 1.1: stack operations\n";
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(24);
		mstack.push(65);
		mstack.push(13);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);

		std::cout << "TEST 1.2: copy constructor\n";
		MutantStack<int> s2(mstack);
		MutantStack<int>::iterator it2 = s2.begin();
		MutantStack<int>::iterator ite2 = s2.end();
		++it2;
		--it2;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}

		std::cout << "TEST 1.3: copy assignment operator\n";
		MutantStack<int> s3;
		s3 = mstack;
		MutantStack<int>::iterator it3 = s3.begin();
		MutantStack<int>::iterator ite3 = s3.end();
		++it3;
		--it3;
		while (it3 != ite3)
		{
			std::cout << *it3 << std::endl;
			++it3;
		}
	}
	{
		std::cout << "\nTEST 2: list\n";

    	std::list<int> mlist;

    	mlist.push_back(5);
    	mlist.push_back(17);
    	std::cout << mlist.back() << std::endl;

    	mlist.pop_back();

    	std::cout << mlist.size() << std::endl;

    	mlist.push_back(3);
    	mlist.push_back(5);
    	mlist.push_back(737);
    	mlist.push_back(24);
    	mlist.push_back(65);
    	mlist.push_back(13);
    	mlist.push_back(0);

    	std::list<int>::iterator it = mlist.begin();
    	std::list<int>::iterator ite = mlist.end();

    	++it;
    	--it;
    	while (it != ite)
    	{
        	std::cout << *it << std::endl;
        	++it;
    	}
	}
	return 0;
}
