// TODO: include the necessary headers
#include <iostream>
#include "CellPhone.h"
using namespace std;
using namespace sict;

// TODO: the sict namespace
namespace sict {
	// TODO: definition for display(...) 
	void display(const CellPhone& cellphone) {
		cout << "Phone " << cellphone.m_model << " costs $" << cellphone.m_price << endl;
	}

}
#pragma once
