#include "vector.hpp"

#include <cassert>

#define eachin(i, v) (std::size_t i = 0; i < v.size(); ++i)

void test_empty_vector()
{
	Vector<int> v;
	assert(v.size() == 0);
}

void test_equal_operator_copies_size()
{
	Vector<int> v, w(10);
	
	assert(v.size() == 0);
	assert(w.size() == 10);
	
	v = w;
	
	assert(v.size() == 10);
	assert(w.size() == 10);
}

void test_equal_operator_copies_data()
{
	Vector<std::size_t> v, w(10);

	for eachin(i, w)
		w[i] = i;

	v = w;

	for eachin(i, v)
		assert(v[i] == i);

	for eachin(i, w)
		w[i] = i + 1;

	for eachin(i, v) {
		assert(v[i] == i);
		assert(w[i] == i + 1);
	}
}

void test_range_based_loop()
{
	Vector<std::size_t> v(10);

	for eachin(i, v)
		v[i] = i + 137;

	std::size_t iterated = 0;
	
	for (auto item : v) {
		assert(item == v[iterated]);
		iterated++;
	}
	
	assert(iterated == v.size());
}

int main(int argc, char **argv)
{
	test_empty_vector();
	test_equal_operator_copies_size();
	test_equal_operator_copies_data();
	test_range_based_loop();
	return 0;
}