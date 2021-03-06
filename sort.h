
#pragma once

#include <algorithm>
#include <numeric>

namespace irwincolor
{

template <typename T> std::vector<unsigned int> sortidx(const std::vector<T>& v)
{
	// Instead of sorting a vector v, sort an index array that gives
	// the ascending sorted values v[idx[0: ]].

	// initialize original index locations
	std::vector<unsigned int> idx(v.size());
	std::iota(idx.begin(), idx.end(), 0);

	// sort indices based on comparing values in v
	std::sort(idx.begin(), idx.end(), [&v](unsigned int i1, unsigned int i2) {return v[i1] < v[i2];});

	return idx;
}

} // namespace irwincolor

