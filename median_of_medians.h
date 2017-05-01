#pragma once

#ifndef MEDIAN_OF_MEDIANS_H
#define MEDIAN_OF_MEDIANS_H
#include <vector>
#include <algorithm>

bool comparePtr(int* a, int* b);
int median_of_5(std::vector<int> & a, int left);
int median_of_medians(std::vector<int> a, int left, int right);

#endif // !1
