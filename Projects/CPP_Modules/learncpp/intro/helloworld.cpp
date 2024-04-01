#include <iostream>

int	add(int, int);

int main()
{
	int	x, y;
	std::cout << "Enter a number x: ";
	std::cin >> x;
	std::cout << "Enter a number y: ";
	std::cin >> y;
	std::cout << "Result: " << add(x, y) << "\n";
	return (0);
}
