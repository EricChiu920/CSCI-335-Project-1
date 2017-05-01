#include "median_quick_select.h"
#include "median_of_three.h"

//Modified quick select function written by Mark Allen Weiss, author of Data Structures and Algorithm Analysis in C++ (Fourth Edition).
//Code found at http://users.cis.fiu.edu/~weiss/dsaa_c++4/code/ Sort.h link; quick select portion.
//quick select can now take a function of your choosing to find a pivot.

/**
* Internal selection method that makes recursive calls.
* Uses a pivot function of choice partitioning and a cutoff of 25.
* Places the kth smallest item in a[k-1].
* left is the left-most index of the subarray.
* right is the right-most index of the subarray.
* num is the desired rank (1 is minimum) in the entire array.
*/

							//pivot function to find a pivot for quick select			, vector to find the median of
int median_quick_select(int pivot_f(std::vector<int> random_vector, int left, int right), std::vector<int> & random_vector, int left, int right, int num)
{
	if (left + 25 <= right) //if vector is smaller than 25 use std sort to find the median.
	{
		int pivot = pivot_f(random_vector, left, right); //Returns position of the pivot
		std::swap(random_vector[pivot], random_vector[right]);
		pivot = random_vector[right]; //make pivot the value instead of position so you can compare.

		int i = left - 1; //quick select from textbook uses ++i which increments first so I need to initialize to left - 1 or it seems to fail to check the first element.
		int j = right; //same for right
		for (; ;)
		{
			while (random_vector[++i] < pivot) {}
			while (pivot < random_vector[--j]) {}

			if (i < j)
				std::swap(random_vector[i], random_vector[j]);
			else
				break;
		}

		std::swap(random_vector[i], random_vector[right]); //Restore pivot

		if (num <= i)
			median_quick_select(pivot_f, random_vector, left, i - 1, num);
		else if (num > i)
			median_quick_select(pivot_f, random_vector, i + 1, right, num);
	}
	else
	{
		std::sort(random_vector.begin() + left, random_vector.begin() + right + 1);
		return random_vector.at((random_vector.size() - 1) / 2);
	}
}