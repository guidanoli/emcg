#include "vector.hpp"

#include <assert.h>

int main(int argc, char **argv)
{
	Vector<std::size_t> v(10);
	assert(v.size() == 10);
	for (std::size_t i = 0; i < v.size(); ++i) {
		v.set(i, i*i);
		assert(v.get(i) == i*i);
	}
	return 0;
}