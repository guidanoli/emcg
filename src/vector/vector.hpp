#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cstddef>
#include <cassert>
#include <iostream>

template<typename T>
class Vector
{
public:
	class iterator
	{
	public:
		iterator(T *ptr) : ptr(ptr) {}
		iterator& operator++() { ++ptr; return *this; }
		bool operator!=(const iterator &it) const { return ptr != it.ptr; }
		const T &operator*() const { return *ptr; }
	private:
		T *ptr;
	};
private:
	T *data;
	std::size_t dim;
public:
	Vector()                    : dim(0),     data(nullptr) {}
	Vector(std::size_t dim)	    : dim(dim),   data(new T[dim]) {}
	Vector(const Vector& v)     : dim(v.dim), data(new T[v.dim]) {}
	Vector(Vector&& v) noexcept : dim(v.dim), data(v.data) { v.data = nullptr; }

	std::size_t size() const { return dim; }

	T& operator[](std::size_t index) const {
		assert(index < dim);
		return data[index];
	}

	Vector &operator=(const Vector &w) {
		if (w.dim != dim) {
			if (dim != 0)
				delete[] data;
			if (w.dim != 0)
				data = new T[w.dim];
			else
				data = nullptr;
			dim = w.dim;
		}
		for (std::size_t i = 0; i < dim; ++i)
			data[i] = w.data[i];
		return *this;
	}

	Vector &operator=(Vector &&w) noexcept {
		dim = w.dim;
		std::swap(data, w.data);
		return *this;
	}

	iterator begin() { return iterator(data); }

	iterator end() { return iterator(data + dim); }

	~Vector() {
		if (data != nullptr)
			delete[] data;
	}
};

#endif