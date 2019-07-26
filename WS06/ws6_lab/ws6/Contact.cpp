//workshop 6 in_lab
//Student Name: Chen Zhao
//Student No.: 120122189
//Section:SAA

#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
namespace sict {
	Contact::Contact() {
		strncpy_s(name, "?", 1);
		phone = nullptr;
		amt = 0;
	}
	Contact::Contact(const char* n_, const long long int* p_, int num) {
		bool valid = (n_ != nullptr && num >= 0);
		if (valid) {
			int remain;
			long long int temp;

			strncpy_s(name, n_, max_name_size);
			name[max_name_size] = '\0';

			phone = nullptr;
			amt = 0;

			long long int * phone2 = new long long int[num];
			int size = 0;
			for (int i = 0; i < num; i++) {
				remain = 0;
				temp = p_[i];
				remain = temp % 10000000;
				valid = (remain >= 1000000) ? true : false;
				if (valid) {
					temp = (temp - remain) / 10000000;
					remain = temp % 1000;
					valid = (remain >= 100) ? true : false;
					if (valid) {
						temp = (temp - remain) / 1000;
						valid = (temp > 0 && temp <= 99) ? true : false;
					}
				}
				if (valid) {
					phone2[size] = p_[i];
					size++;
				}
				/*
				if (valid) {
					long long int* phone2 = nullptr;
					phone2 = new long long int[++amt];
					for (int j = 0; j < amt - 1; j++) {
						phone2[j] = phone[j];
					}
					phone2[amt - 1] = p_[i];
					delete[] phone;
					phone = phone2;
				}*/
			}
			phone = new long long int[size];
			for (int i = 0; i < size; i++) {
				phone[i] = phone2[i];
			}
			amt = size;
			delete[] phone2;
			phone2 = nullptr;
		}
		else {
			phone = nullptr;
			*this = Contact();
		}
	}


	Contact::~Contact() {
		delete[] phone;
	}

	bool Contact::isEmpty() const {
		bool empty = false;
		if (amt > 0)
			empty= false;
		else if(strcmp(name, "?") == 0 || name == nullptr || strlen(name)==0) {
			empty= true;
		}
		return empty;
	}

	void Contact::display() const {

		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;

			if (amt != 0) {
				long long int tmp;
				int numarray[12];
		
				for (int i = 0; i < amt; i++) {
					tmp = phone[i];  //     11416 833 9982     124163456789
					for (int j = 11; j >= 0; j--) {
						numarray[j] = tmp % 10;
						tmp = (tmp - numarray[j]) / 10;
					}
					if (numarray[0] == 0)
					{
						cout << "(+" << numarray[1] << ") ";
					}
					else {
						cout << "(+" << numarray[0] << numarray[1] << ") ";
					}
					cout << numarray[2] << numarray[3] << numarray[4] << " "
						<< numarray[5] << numarray[6] << numarray[7] << "-"
						<< numarray[8] << numarray[9] << numarray[10] << numarray[11] << endl;
				}
			}
		}
	}
}
 