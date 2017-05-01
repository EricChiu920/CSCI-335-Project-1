#include "median_selection_sort.h"

//Returns median using a inplace selection sort stopped halfway.

int median_selection_sort(std::vector<int> random_set)
{
	if (random_set.size() > 50000)
	{
		throw 5; //Throw a error if amount of intergers is greater than fifty thousand.
	}
	int min_position;

	auto start = std::chrono::steady_clock::now(); //Start timing the runtime of the method
	for (int i = 0; i < ((random_set.size() + 1) / 2); i++) //Go through the vector until halfway
	{
		min_position = i; //Min as first unsorted element to have something to compare
		for (int j = i + 1; j < random_set.size(); j++)
		{
			if (random_set.at(j) < random_set.at(min_position))
			{
				min_position = j;
			}
		}

		if (min_position != i)
		{
			//Move the smallest found element to where it belongs. (If it isn't already)
			std::swap(random_set[i], random_set[min_position]);
		}
	}
	auto end = std::chrono::steady_clock::now(); //End timing
	auto diff = end - start; //Store time
	std::cout << ", runtime: " << std::chrono::duration <double, std::milli>(diff).count() << "ms"; //Print runtime

	std::cout << ", median: ";
	return random_set.at((random_set.size() - 1) / 2);
}