#include "median_of_medians.h"
#include "median_of_three.h"

bool comparePtr(int* a, int* b) //allow std::sort to compare a vector of pointers
{
	return (*a < *b);
}

int median_of_5(std::vector<int> & a, int left) //returns the median of five numbers using 6 comparisons
{
	if (a.at(left) < a.at(left + 1))
		std::swap(a.at(left), a.at(left + 1));
	if (a.at(left + 2) < a.at(left + 3))
		std::swap(a.at(left + 2), a.at(left + 3));

	if (a.at(left) > a.at(left + 2))
	{
		std::swap(a.at(left), a.at(left + 4));
		if (a.at(left) < a.at(left + 1))
		{
			std::swap(a.at(left), a.at(left + 1));
		}
	}
	else
	{
		std::swap(a.at(left + 2), a.at(left + 4));
		if (a.at(left + 2) < a.at(left + 3))
		{
			std::swap(a.at(left + 2), a.at(left + 3));
		}
	}

	if (a.at(left) > a.at(left + 2))
	{
		if (a.at(left + 1) > a.at(left + 2))
			return left + 1;
		else
			return left + 2;
	}
	else
	{
		if (a.at(left) > a.at(left + 3))
			return left;
		else
			return left + 3;
	}
}

int median_of_medians(std::vector<int> a, int left, int right) //keep taking medians of five so you'll have n/5 medians then take the median of those medians for a pivot.
{
	std::vector<int*> p;
	int * p2 = &a[0];
	int i = left;


	if (left + 5 < right) //keep taking median of fives
	{
		for (i; i + 5 <= right; i += 5)
		{
			p.push_back(&a[median_of_5(a, i)]);
		}
		if (a.size() - i == 4 || a.size() - i == 3) //If there is 3 or 4 extra numbers you take the second smallest of those numbers and add it as a median.
		{											//If there are 1 or 2 extra numbers you ignore them.
			std::sort(a.begin() + i, a.begin() + right + 1);
			p.push_back(&a[i + 1]);
		}

		std::sort(p.begin(), p.end(), comparePtr); //sort the median of fives
		i = (p[p.size() / 2 - 1] - p2); //get the position of the median in vector a.
		return i;
	}
	else
	{
		std::sort(a.begin() + left, a.begin() + right);
		return a.at(a.size() / 2);
	}
}

//Notes
/*Difficulties: I wanted to modify quick select so that it could take either median of 3 
or median of medians as a parameter to find a pivot.

Since I put the median of fives in another vector I couldn't figure out a good way to swap it with right.

(bad)Solution: I made a vector of pointers and kept track of the address' of median of fives.
Then substracted the address of the median of medians using the first element of the vector to find the position.

*/