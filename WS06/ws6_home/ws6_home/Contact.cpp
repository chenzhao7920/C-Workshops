//workshop 6 at_home
//Student Name: Chen Zhao
//Student No.: 120122189
//Section:SAA

#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
namespace sict {
	//set default constructor with safe emptu date
	bool Contact::validphonenum(const long long int p_) {
		long long int w;
	    long long int a;
		long long int n;
		w = p_ / 10000000000;  
		a = (p_ % 10000000000) / 10000000;
		n = p_ % 10000000;
		bool valid = (w > 0 && w <= 99 && a >= 100 && n >= 1000000);
		return valid;
	}
	Contact::Contact() {
		strncpy(name, "?", 1);
		phone = nullptr;
		amt = 0;
	}
	//set three parameter constructor
	Contact::Contact(const char* n_, const long long int* p_, int num) {
		// check parameter validation
		bool valid = (n_ != nullptr && num >= 0);
		if (valid) {
		//	int remain;
			//set data member
			strncpy(name, n_, max_name_size);
			name[max_name_size] = '\0';
			phone = nullptr;
			amt = 0;

			//dynamically allocate a memory size of num
			long long int * phone2 = new long long int[num];
			//temarary varible to record the number of valid phone-number
			int size = 0;
			//check the input phone array
			for (int i = 0; i < num; i++) {		 
				//store each valid phone-number to new membery address
				if (validphonenum(p_[i])) {
					phone2[size] = p_[i];
					size++;
				}
			}
			//allocate memory for current object with the size of valid phone-number, 
			phone = new long long int[size];
			for (int i = 0; i < size; i++) {
				//copy value 
				phone[i] = phone2[i];
			}
			//delete old dynamic memory and reset the pointer to nullptr
			delete[] phone2;
			//to be safe ,make phone2 to nullptr;
			phone2 = nullptr;

		    //store valid number to amt
			amt = size;			 
		}
		else {
			phone = nullptr;
			*this = Contact();
		}
	}

	 
	Contact::Contact(const Contact& src) {
		phone = nullptr;
		*this = src;
	}

	Contact::~Contact() {
		delete[] phone;
	}

	bool Contact::isEmpty() const {
		bool empty = (strcmp(name, "?") == 0 || name == nullptr || strlen(name) == 0);		
		return empty;
	}

	void Contact::display() const {

		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;

			if (amt != 0) {
				//make a int array to store each phone number
				long long int tmp;
				int numarray[12];

				for (int i = 0; i < amt; i++) {
					tmp = phone[i];  //     11416 833 9982     124163456789
					for (int j = 11; j >= 0; j--) {
						numarray[j] = tmp % 10;
						tmp = (tmp - numarray[j]) / 10;
					}
					//if only has 11 digit number, then the first number of this array is 0
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

	Contact& Contact::operator=(const Contact& src) {
		//copy assignment should check if selfcopy
		if (this != &src) {
			strncpy(name, src.name, max_name_size-1);
			name[max_name_size-1] = '\0';
			amt = src.amt;
			// deallocate old dynamic memory
			delete[] phone;
			phone = nullptr;
			if (amt > 0) {
				// allocate dynamic memory for grades
				phone = new long long int[amt];
				for (int i = 0; i < amt; i++)
					// copy data from the source resource
					phone[i] = src.phone[i];
			}
			else {
				phone = nullptr;
			}
		}
		return *this;
	}

	Contact& Contact::operator+=(const long long int p_) {
		
		if (validphonenum(p_) && (!isEmpty())) {	

			long long * phone2 = nullptr;
			phone2 = new long long int[++amt];
 
			for (int i = 0; i < amt - 1; i++) {
				phone2[i] = this->phone[i];
			}

			phone2[amt - 1] = p_;

			delete [] phone;
			phone = nullptr;

			this->phone = new long long int[amt];
			for (int i = 0; i < amt; i++) {
				this->phone[i]= phone2[i];
			}

			delete[] phone2;
			phone2 = nullptr;
			 
		}
		return *this;
	}

}
