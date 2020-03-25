#include "racional.hpp"

#include <iostream>

// Euclid's algorithm
void Racional::simplify()
{
	int r, b = p, a = q;
	do {
		r = b % a;
		b = a;
		a = r;
	} while (r != 0);
	p /= b;
	q /= b;
}

Racional Racional::operator+(const Racional &R)
{
	Racional sum;
	sum.p = p * R.q + q * R.p;
	sum.q = q * R.q;
	sum.simplify();
	return sum;
}

Racional Racional::operator-(const Racional &R)
{
	Racional difference;
	difference.p = p * R.q - q * R.p;
	difference.q = q * R.q;
	difference.simplify();
	return difference;
}

Racional Racional::operator*(const Racional &R)
{
	Racional product;
	product.p = p * R.p;
	product.q = q * R.q;
	product.simplify();
	return product;
}

Racional Racional::operator/(const Racional &R)
{
	Racional division;
	division.p = p * R.q;
	division.q = q * R.p;
	division.simplify();
	return division;
}

void Racional::show()
{
	if (q == 1 || q == -1)
		std::cout << p * q << std::endl;
	else
		std::cout << p << "/" << q << std::endl;
}
