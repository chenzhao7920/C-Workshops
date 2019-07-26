// OOP244 Workshop 9: Function Templates
// File: Data.h
// Version: 2.0
// Date: 2017/12/15
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////
//student name: Chen Zhao
//Student No:120122189
//Section: SAA
#ifndef SICT_DATA_H
#define SICT_DATA_H
#include <iostream>
#include <iomanip>

namespace sict {
	 
	// These number defines the output column width for a single data field

		const int COLUMN_WIDTH = 15;
		const int COLUMN_NAME = 20;
	//function max
	template <typename T>
	T max(const T* data, int n);
	//function min
	template <typename T>
	T  min(const T* data, int n);

	//function sum
	template <typename T>
	T  sum(const T* data, int n);
	//function average
	template <typename T>
	double average(const T* data, int n);
	//function  read
	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		bool readwell = true;
		for (int i = 0; i < n && readwell; i++) {
			input.get();
			input >> data[i];
			readwell = !input.fail();
		}
		return readwell;
	}
	//function  display
	template <typename T>
	void display(const char* name, const T* data, int n) {
		std::cout << std::right << std::setw(COLUMN_NAME) << name;
		for (int i = 0; i < n; i++) {
			std::cout << std::setw(COLUMN_WIDTH) << data[i];
		}  
		std::cout << std::endl;
	}
	 
 
	//function  readRow
	template <class T>
	bool  readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,...

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	
		void answers(const int*, const int*, const int*, const double*, const int*, const int n);
	
}

#endif