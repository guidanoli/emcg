#pragma once
class Racional
{
private:
	int p, q;
	void simplify();
public:
	Racional(Racional &R) : p(R.p), q(R.q) {}
	Racional(int p = 0, int q = 1) : p(p), q(q) {}
	Racional operator+(const Racional &R);
	Racional operator-(const Racional &R);
	Racional operator*(const Racional &R);
	Racional operator/(const Racional &R);
	void show();
};