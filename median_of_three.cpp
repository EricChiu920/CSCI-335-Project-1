#include "median_of_three.h"

/**
* Return median of left, center, and right.
* Order these and hide the pivot.
*/
int median3(std::vector<int> a, int left, int right)
{
	int center = (left + right) / 2;

	if (a[left] < a[center])
	{
		if (a[center] < a[right]) //left < center < right
			return center;
		else if (a[left] < a[right]) // left < center, right < center, left < right
			return right;
		else
			return left;
	}
	else
	{
		if (a[left] < a[right]) //center < left < right
			return left;
		else if (a[center] < a[right]) //center < left, right < left, center < right
			return right;
		else
			return center;
	}
}