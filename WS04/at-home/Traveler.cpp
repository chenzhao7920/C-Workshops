// TODO: add file header comments here
// Student Name: CHEN ZHAO
// Student ID:120122189
// Section:SAA
// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Traveler.h"
#define _CRT_SECURE_NO_WARNINGS
// TODO: continue your namespace here
using namespace std;
using namespace sict;
// TODO: implement the default constructor here
Traveler::Traveler() {
	strcpy(firstName, "\0");
	strcpy(lastName, "\0");
	strcpy(destination, "?");
	yearOfdeparture = 0;
	monthOfdeparture = 0;
	dayOfdeparture = 0;
}
Traveler::~Traveler() {
}

// TODO: implement the constructor with 3 parameters here
Traveler::Traveler(const char *f_, const char *l_, const char *des_) {
	bool valid = f_ != nullptr && l_ != nullptr && des_ != nullptr &&strlen(f_) != 0 && strlen(l_) != 0 && strlen(des_) != 0;
 
	if (valid) {
 

		strncpy(firstName, f_, max_name_size-1);
		strncpy(lastName, l_, max_name_size-1);
		strncpy(destination, des_, max_destination_size-1);

		firstName[max_name_size - 1] = '\0';
		lastName[max_name_size - 1] = '\0';
		destination[max_destination_size - 1] = '\0';

		yearOfdeparture = 2017;
		monthOfdeparture = 7;
		dayOfdeparture = 1;

	}
	else {
		*this = Traveler();
	}
}
// TODO: implement the constructor with 6 parameters here
Traveler::Traveler(const char *f_, const char *l_, const char *des_,int y_,int m_, int day) {
	bool valid = y_ >= 2019 && y_ <= 2022 && m_ >= 1 && m_ <= 12 && day >= 1 && day <= 31;
	if (valid == true) {
		*this = Traveler(f_, l_, des_);
		if (isEmpty())
			*this = Traveler();
		else {
			yearOfdeparture = y_;
			monthOfdeparture = m_;
			dayOfdeparture = day;
		}
	}
	else {
		*this = Traveler();
	}
}
// TODO: implement isEmpty query here
bool Traveler::isEmpty() const {
	bool isempty = strcmp(firstName, "\0") == 0;
	return isempty;
}

// TODO: implement display query here

void Traveler::display() const {
	bool empty = isEmpty();
	if (!empty) {
		cout << lastName << ", "<< firstName << " goes to " << destination
			<< " on " << yearOfdeparture << "/";
		cout.width(2);
		cout.fill('0');
		cout << monthOfdeparture << "/";
		cout.width(2);
		cout.fill('0');
		cout << dayOfdeparture << endl;
	}
}
// TODO: implement  name query here
const char* Traveler::name() const {

		return firstName;
}

// TODO: implement  canTravelWith here
bool Traveler::canTravelWith(const Traveler& friends) const {
	bool can = strcmp(destination, friends.destination) == 0
		    && yearOfdeparture == friends.yearOfdeparture
		    && monthOfdeparture == friends.monthOfdeparture
		    && dayOfdeparture == friends.dayOfdeparture;
	return can;
}

// TODO: implement  deconstructor here
 