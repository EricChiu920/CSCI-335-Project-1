//Created by Eric Chiu for CSCI 335 Project 1.
//Written and compiled in Visual Studio 2015
//Date: 2016, Nov, 2
//This program finds the median of numbers in a text file using various methods and times the various methods.
/***Warning: For simplicity for coding (And project requirements), in the case of a even amount of numbers, this program will only
return the first of the two middle elements. For example for 10 elements it only returns the fifth element.
It does NOT return the mean of the fifth and sixth element.***/

#include <iostream>
#include <fstream>
#include <string>
#include "median_selection_sort.h"
#include "median_std_sort.h"
#include "median_merge_sort.h"
#include "median_binary_heap_sort.h"
#include "median_quick_select.h"
#include "median_of_three.h"
#include "median_of_medians.h"

//Sorting method, vector that holds inputs, input name, sorting method name
template<class Iter>
void print_function(int median_sort(std::vector<int> random_vector), std::vector<int> random_vector, Iter names, std::string method);

template<class Iter>
void print_qfunction(int pivot_f(std::vector<int> random_vector, int left, int right), std::vector<int> random_vector, int left, int right, Iter name, std::string method);

int main()
{
	int run_count = 1; //We run the entire program multiple times to attempt to eliminate any extreme times.
	int numbers = 0; //Temporary holder of numbers to put into a vector.
	int inputs = 0; //Go thorough the list of names of input files.
	std::vector<int> input_vector; //Holds the input of random numbers

	//Holds the input file names
	//std::vector<string> input_name_vectors = {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt", "input9.txt"};
	std::vector<string> input_name_vectors = { "random_set_1.txt", "random_set_2.txt", "random_set_3.txt", "random_set_4.txt",
	"random_set_5.txt", "random_set_6.txt", "random_set_7.txt", "random_set_8.txt", "random_set_9.txt" }; //Test files

	while (run_count <= 3) //Run program 3 times to attempt to reduce any extreme values
	{
		std::cout << "Starting run " << run_count << std::endl << std::endl;
		inputs = 0;
		while (inputs < input_name_vectors.size())
		{
			std::ifstream random_set(input_name_vectors.at(inputs));
			if (random_set.is_open())
			{
				while (random_set >> numbers)
				{
					input_vector.push_back(numbers);
				}
				try //Check if file is too large for selection sort.
				{
					print_function(median_selection_sort, input_vector, input_name_vectors.at(inputs), "Selection sort"); //Print results
				}
				catch (int param)
				{
					std::cout << " File size is larger than 50,000. It is too large for selection sort so it will be skipped." << std::endl;
				}
				print_function(median_std_sort, input_vector, input_name_vectors.at(inputs), "Standard sort");
				print_function(median_merge_sort, input_vector, input_name_vectors.at(inputs), "Merge sort");
				print_function(median_binary_heap_sort, input_vector, input_name_vectors.at(inputs), "Binary heap sort");
				print_qfunction(median3, input_vector, 0, input_vector.size() - 1, input_name_vectors.at(inputs), "Quick sort");
				print_qfunction(median_of_medians, input_vector, 0, input_vector.size() - 1, input_name_vectors.at(inputs), "Median of Medians");
			}
			else
			{
				std::cout << "  File " << input_name_vectors.at(inputs) << " could not be opened." << std::endl;
			}
			inputs++; //Read next input file
			input_vector.clear(); //Clear vector for next input file

			random_set.close();
			std::cout << std::endl;
		}
		std::cout << "End run " << run_count << std::endl << std::endl;
		run_count++;
	}
	return 0;
}

//Print functions
template<class Iter> //Median sort function, takes a vector                 //Vector to be sorted  //File name.   //Sorting method
void print_function(int median_sort(std::vector<int> random_vector), std::vector<int> random_vector, Iter name, std::string method)
{
	std::cout << "  " << name << ", size: " << random_vector.size();
	std::cout << median_sort(random_vector); //Return median
	std::cout << ", method: " << method << std::endl;
}

template<class Iter>                 //Pivot function, takes vector, left, right                //Vector to be sorted.   //left    //right     //name    //sorting method
void print_qfunction(int pivot_f(std::vector<int> random_vector, int left, int right), std::vector<int> random_vector, int left, int right, Iter name, std::string method)
{
	int m = -1;
	std::cout << "  " << name << ", size: " << random_vector.size();
	auto start = std::chrono::steady_clock::now(); //Start timing the runtime of the method
	m = median_quick_select(pivot_f, random_vector, left, right, (random_vector.size() - 1) / 2); //Return Median
	auto end = std::chrono::steady_clock::now(); //End timing
	auto diff = end - start; //Store time
	std::cout << ", runtime: " << std::chrono::duration <double, std::milli>(diff).count() << "ms"; //Print runtime

	std::cout << ", median: " << m;
	std::cout << ", method: " << method << std::endl;
}