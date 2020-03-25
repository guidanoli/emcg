#include "rational.hpp"

#include <iostream>

void Rational::show()
{
	if (q == 1 || q == -1)
		std::cout << p * q << std::endl;
	else
		std::cout << p << "/" << q << std::endl;
}
