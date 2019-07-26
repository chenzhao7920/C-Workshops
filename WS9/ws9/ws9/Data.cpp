// OOP244 Workshop 9: Function Templates
// File: Data.cpp
// Version: 2.0.1
// Date: 2017/12/17
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the answers and readRow functions
// Chris     2017.12.17 removed answers to Q1
///////////////////////////////////////////////////
//student name: Chen Zhao
//Student No:120122189
//Section: SAA

#include <iostream>
#include "Data.h"
using namespace std;
namespace sict {
	
	
	// answers outputs statistics for visual validation of data
	//

	void  answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		std::cout << "Population change from " << min(year, n) << " to " << max(year, n) << " is "
			<< std::fixed << std::setprecision(2) << (max(population, n) - min(population, n)) / 1000000.0
			<< " million" << std::endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		if (violentCrimeRate[n - 1] < violentCrimeRate[0]) {
			std::cout << "Violent Crime trend is down" << std::endl;
		}
		else if (violentCrimeRate[n - 1] > violentCrimeRate[0]) {
			std::cout << "Violent Crime trend is up" << std::endl;
		}
		else {
			std::cout << "Violent Crime trend is equal" << std::endl;
		}

		// Q3 print the GTA number accurate to 0 decimal places

		std::cout << "There are " << average(grandTheftAuto, n) / 1000000.0 << " million Grand Theft Auto incidents on average a year" << std::endl;

		// Q4. Print the min and max violentCrime rates
		std::cout << std::setprecision(0) << "The Minimum Violent Crime rate was " << min(violentCrimeRate, n) << std::endl;
		std::cout << "The Maximum Violent Crime rate was " << max(violentCrimeRate, n) << std::endl;


	}
	template <typename T>
	T  sum(const T* data, int n) {
		T tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp += data[i];
		}
		return tmp;
	}
	template <typename T>
	T max(const T* data, int n) {
		T tmp = data[0];
		for (int i = 1; i < n; i++) {
			if (tmp < data[i]) tmp = data[i];
		}
		return tmp;
	}
	template <typename T>
	T  min(const T* data, int n) {
		T tmp = data[0];
		for (int i = 1; i < n; i++) {
			if (tmp > data[i]) tmp = data[i];
		}
		return tmp;
	}
	template <typename T>
	double average(const T* data, int n) {
		double tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp += data[i];
		}
		tmp /= n;
		return tmp;
	}
	T max(const T* data, int n) {
		T tmp = data[0];
		for (int i = 1; i < n; i++) {
			if (tmp < data[i]) tmp = data[i];
		}
		return tmp;
	}
}  