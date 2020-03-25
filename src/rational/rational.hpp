#ifndef __RATIONAL_H__
#define __RATIONAL_H__
class Rational
{
private:
	int p, q;
	inline void simplify()
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
public:
	Rational(Rational &R) : p(R.p), q(R.q) {}
	Rational(int p = 0, int q = 1) : p(p), q(q) {}

	Rational operator+(const Rational &R)
	{
		Rational sum;
		sum.p = p * R.q + q * R.p;
		sum.q = q * R.q;
		sum.simplify();
		return sum;
	}
	Rational operator-(const Rational &R)
	{
		Rational difference;
		difference.p = p * R.q - q * R.p;
		difference.q = q * R.q;
		difference.simplify();
		return difference;
	}
	Rational operator*(const Rational &R)
	{
		Rational product;
		product.p = p * R.p;
		product.q = q * R.q;
		product.simplify();
		return product;
	}
	Rational operator/(const Rational &R)
	{
		Rational division;
		division.p = p * R.q;
		division.q = q * R.p;
		division.simplify();
		return division;
	}
	bool operator==(const Rational &R)
	{
		return p * R.q == q * R.p;
	}
	bool operator!=(const Rational &R)
	{
		return !(*this==R);
	}
	void show();
};
#endif