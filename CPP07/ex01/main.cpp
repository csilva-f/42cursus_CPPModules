#include "iter.hpp"

int main(void)
{
	int		a[] = {5, 6, -4, 0, 6, -7};
	char	b[] = "carolina";

	std::cout << "INICIO\na =";
	for (int i = 0; i < 6; i++)
		std::cout << " " << a[i];
	std::cout << "\n\n";
	iter(a, 6, increment<int>);
	iter(b, 8, printc<const char>);
	std::cout << "\n\nFIM\na =";
	for (int i = 0; i < 6; i++)
		std::cout << " " << a[i];
	std::cout << "\n";
	return 0;
}
