#include "median_merge_sort.h"
//merge_sort function code taken from http://en.cppreference.com/w/cpp/algorithm/inplace_merge

template<class Iter>
void merge_sort(Iter first, Iter last)
{
	if (last - first > 1)
	{
		Iter middle = first + (last - first) / 2;
		merge_sort(first, middle);
		merge_sort(middle, last);
		std::inplace_merge(first, middle, last);
	}
}

int median_merge_sort(std::vector <int> random_set)
{
	auto start = std::chrono::steady_clock::now(); //Start timing the runtime of the method
	merge_sort(random_set.begin(), random_set.end());
	auto end = std::chrono::steady_clock::now(); //End timing
	auto diff = end - start; //Store time
	std::cout << ", runtime: " << std::chrono::duration <double, std::milli>(diff).count() << "ms"; //Print runtime

	std::cout << ", median: ";
	return random_set.at((random_set.size() - 1) / 2);
}