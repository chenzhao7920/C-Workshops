// TODO: add file header comments here
// Student Name: CHEN ZHAO
// Student ID:120122189
// Section:SAA
// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Traveler.h"

// TODO: continue your namespace here
using namespace std;
using namespace sict;
// TODO: implement the default constructor here
Traveler::Traveler() {
	strcpy(firstName, "?");
	strcpy(lastName, "?");
	strcpy(destination, "?");
}
// TODO: implement the constructor with 3 parameters here
Traveler::Traveler(const char *f_,const char *l_,const char *d_) {
	bool valid = f_ != nullptr && l_ != nullptr && d_ != nullptr && strlen(f_) > 0 && strlen(l_) > 0 && strlen(d_) > 0;
	if (valid) {
		firstName[max_name_size] = '\0';
		lastName[max_name_size] = '\0';
		destination[max_destination_size] = '\0';
		strncpy(firstName, f_, max_name_size);
		strncpy(lastName, l_, max_name_size);
		strncpy(destination, d_, max_destination_size);
	}
	else {
		*this = Traveler();
	}
}
// TODO: implement isEmpty query here
bool Traveler::isEmpty() const {
	bool isempty = strcmp(firstName, "?") == 0;
	return isempty;
}
// TODO: implement display query here

void Traveler::display() const {
	bool empty=isEmpty();
	if (empty) {
		cout << "--> Not a valid traveler! <-- " << endl;
	}
	else {
		cout << firstName << ' ' << lastName << " goes to  " << destination << endl;
	}
}

Traveler::~Traveler() {
}
