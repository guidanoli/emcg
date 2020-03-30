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
	Vector(std::size_t n) : n(n), data(new T[n]) {}

	Vector(const Vector& v) : n(v.n), data(new T[v.n]) {}

	std::size_t size() const { return n; }

	T get(std::size_t index) const {
		assert(index < n);
		return data[index];
	}

	void set(std::size_t index, T value) {
		assert(index < n);
		data[index] = value;
	}
	
	~Vector() { delete[] data; }
};
#endif