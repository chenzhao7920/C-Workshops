// Workshop 2 - Dynamic Memory
// name:CHEN ZHAO
// student ID:120122189
// saction:SAA
// TODO: include the necessary headers
#include <iostream>
#include "CellPhone.h"
using namespace std;
using namespace sict;

// TODO: the sict namespace
namespace sict {
// TODO: definition for display(...) 
	void display(const CellPhone& phone) {
		cout << "Phone " << phone.m_model << " costs $" << phone.m_price <<"!"<< endl;
	}
	void display(const CellPhone *phone, int amt) {
		float lowest = phone[0].m_price;
		for (int i = 0; i < amt; i++) {
		        cout<<i+1<<". ";
                        display(phone[i]); 
			if (lowest > phone[i].m_price) 
				lowest = phone[i].m_price;
	
		}
		cout << "------------------------------" << endl;
		cout << "The cheapest phone costs $" << lowest <<"."<< endl;
	}
}
    
