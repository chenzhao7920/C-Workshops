// TODO: add file header comments here
// Student Name: CHEN ZHAO
// Student ID:120122189
// Section:SAA
// TODO: add header file guard here
#ifndef _SICT_TRAVELER_H_
#define _SICT_TRAVELER_H_
// TODO: declare your namespace here
namespace sict {
	// TODO: define the constants here
	int const max_destination_size = 32;
	int const max_name_size = 16;
	// TODO: define the Traveler class here
	class Traveler
	{
		char firstName[max_name_size + 1];
		char lastName[max_name_size + 1];
		char destination[max_destination_size + 1];
	public:
		Traveler();
		Traveler(const char *, const char *, const char*);
		~Traveler();
		bool isEmpty() const;
		void display() const;
	};
}
#endif 
