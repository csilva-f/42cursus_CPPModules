#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;
	std::cout << "TESTE 1\nInicio: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "Fim: a = " << a << ", b = " << b << std::endl;
	std::cout << "\nTESTE 2\nmin(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "\nTESTE 3\nInicio: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "Fim: c = " << c << ", d = " << d << std::endl;
	std::cout << "\nTESTE 4\nmin(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	return 0;
}
