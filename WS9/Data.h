// OOP244 Workshop 9: Function Templates
// File: Data.h
// Version: 2.0
// Date: 2017/12/15
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////




namespace sict {
	// These number defines the output column width for a single data field

	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//


	// min returns the smallest item in data
	//

        
	// sum returns the sum of n items in data
	//    
   
	// average returns the average of n items in data
	//

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	// display inserts n items of data into std::cout
	//

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

