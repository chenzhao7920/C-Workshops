// Workshop 2 - Dynamic Memory
// name:CHEN ZHAO
// student ID:120122189
// saction:SAA
// TODO: header safeguards
#ifndef _SICT_CELLPHONE_H_
#define _SICT_CELLPHONE_H_
// TODO: sict namespace

namespace sict {
// TODO: define the structure CellPhone in the sict namespace

	struct CellPhone
	{
		char m_model[32];
		float m_price;
	};
// TODO: declare the function display(...),
// //         also in the sict namespace

	void display(const CellPhone& phone);
	void display(const CellPhone* phone, int amt);
}
#endif 


