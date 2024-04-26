#include "Span.hpp"
#include <exception>
#include <iostream>
#include <iterator>
#include <limits>

int main()
{
	try
	{
		Span	sp = Span(10);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "Longest span: " << sp.longestSpan() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	try
	{
		Span	sp = Span(10);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "Longest span: " << sp.longestSpan() << "\n";

		std::vector<int>	cont1;
		int nbrs1[] = {2, 58, 6, -45, 36, 7, 14, 40, 39, 22};
		int	n1 = sizeof(nbrs1) / sizeof(nbrs1[0]);
		cont1.insert(cont1.end(), nbrs1, nbrs1 + n1);

		sp.addNumbers(cont1.begin(), cont1.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "Longest span: " << sp.longestSpan() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	try
	{
		Span	sp = Span(10);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "Longest span: " << sp.longestSpan() << "\n";

		std::vector<int>	cont2;
		int nbrs2[] = {7, 14, 40, 39, 22};
		int	n2 = sizeof(nbrs2) / sizeof(nbrs2[0]);
		cont2.insert(cont2.end(), nbrs2, nbrs2 + n2);

		sp.addNumbers(cont2.begin(), cont2.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "Longest span: " << sp.longestSpan() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	return 0;
}
