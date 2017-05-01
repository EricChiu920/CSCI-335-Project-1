#pragma once

#ifndef MEDIAN_QUICK_SELECT_H
#define MEDIAN_QUICK_SELECT_H
#include <vector>
#include <algorithm>

//Modified quick select function written by Mark Allen Weiss, author of Data Structures and Algorithm Analysis in C++ (Fourth Edition).
//Code found at http://users.cis.fiu.edu/~weiss/dsaa_c++4/code/ Sort.h link; quick select portion.

int median_quick_select(int pivot_f(std::vector<int> random_vector, int left, int right), std::vector<int> & random_vector, int left, int right, int num);

#endif