#include "median_binary_heap_sort.h"
//Entire BinaryHeap written by Mark Allen Weiss, author of Data Structures and Algorithm Analysis in C++ (Fourth Edition).
//Code found at http://users.cis.fiu.edu/~weiss/dsaa_c++4/code/ BinaryHeap.h link

int median_binary_heap_sort(std::vector<int> random_set)
{
	BinaryHeap<int> bheap;

	auto start = std::chrono::steady_clock::now(); //Start timing the runtime of the method
	for (int i = 0; i < random_set.size(); i++) //Insert items from vector into heap
	{
		bheap.insert(random_set.at(i));
	}

	//Delete items until we have the median on the top of the heap
	for (int j = 1; j <= ((random_set.size() - 1) / 2); j++) //Stop at (n/2) - 1 items so median is on top of the list
	{													   //n/2 items would delete the median
		bheap.deleteMin();
	}
	auto end = std::chrono::steady_clock::now(); //End timing
	auto diff = end - start; //Store time
	std::cout << ", runtime: " << std::chrono::duration <double, std::milli>(diff).count() << "ms"; //Print runtime

	std::cout << ", median: ";
	return bheap.findMin();
}