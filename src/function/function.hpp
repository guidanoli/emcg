#pragma once

#include <functional>

class Function
{
public:
	Function(std::function<float(float)> f, float x0, float xn, int n) :
		f(f), x0(x0), xn(xn), n(n) {}
	void plot() const;
private:
	std::function<float(float)> f;
	float x0;
	float xn;
	int n;
};