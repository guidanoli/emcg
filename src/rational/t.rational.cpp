#include "rational.hpp"

#include <assert.h>

void main()
{
	// Equality
	assert(Rational(1) == Rational(1));
	assert(Rational(2, 2) == Rational(2, 2));
	assert(Rational(-2, -2) == Rational(2, 2));
	assert(Rational(-2, 2) == Rational(2, -2));
	assert(Rational(-2, -2) == Rational(7, 7));

	// Inequality
	assert(Rational(-1) != Rational(1));
	assert(Rational(-1) != Rational(0));
	assert(Rational(-1) != Rational(2));
	assert(Rational(-2, 2) != Rational(2, 2));
	assert(Rational(-2, 2) != Rational(4, 4));

	// Addition
	assert(Rational(1) + Rational(2) == Rational(3));
	assert(Rational(1, 2) + Rational(3, 4) == Rational(5, 4));

	// Subtraction
	assert(Rational(1) - Rational(2) == Rational(-1));
	assert(Rational(1, 2) - Rational(3, 4) == Rational(-1, 4));

	// Multiplication
	assert(Rational(3) * Rational(5) == Rational(15));
	assert(Rational(3, 7) * Rational(5, 11) == Rational(15, 77));

	// Division
	assert(Rational(3) / Rational(5) == Rational(3, 5));
	assert(Rational(3, 7) / Rational(5, 11) == Rational(33, 35));
}