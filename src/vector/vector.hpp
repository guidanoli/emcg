#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cstddef>
#include <cassert>
#include <iostream>

template<typename T>
class Vector
{
private:
	T *data;
	std::size_t n;
public:
	Vector()				: n(0),		data(nullptr) {}
	Vector(std::size_t n)	: n(n),		data(new T[n]) {}
	Vector(const Vector& v) : n(v.n),	data(new T[v.n]) {}
	~Vector() { delete[] data; }

	std::size_t size() const { return n; }

	T get(std::size_t index) const {
		return data[index];
	}

	void set(std::size_t index, T value) {
		data[index] = value;
	}
	
	void operator=(const Vector &w) {
		if (w.n != n) {
			if (n != 0)
				delete[] data;
			data = new T[w.n];
			n = w.n;
		}
		for (std::size_t i = 0; i < n; ++i)
			data[i] = w.data[i];
	}
};
#endif