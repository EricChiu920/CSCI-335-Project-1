#include "median_std_sort.h"

//Returns median of numbers using standard sort to sort the list first.
int median_std_sort(std::vector<int> random_set)
{
	auto start = std::chrono::steady_clock::now(); //Start timing the runtime of the method
	std::sort(random_set.begin(), random_set.end()); //Sort vector using standard sort
	auto end = std::chrono::steady_clock::now(); //End timing
	auto diff = end - start; //Store time
	std::cout << ", runtime: " << std::chrono::duration <double, std::milli>(diff).count() << "ms"; //Print runtime

	std::cout << ", median: ";
	return random_set.at((random_set.size() - 1) / 2); //Return median position - 1 since we start at zero.
}