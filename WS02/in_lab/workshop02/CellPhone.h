// name:CHEN ZHAO
// student ID:120122189
// saction:SAA
// TODO: header safeguards
#ifndef _SICT_CELLPHONE_H_
#define _SICT_CELLPHONE_H_
namespace sict {
	struct CellPhone
	{
		char m_model[32];
		float m_price;
	};

	void display(const CellPhone& cellphone);
}
#endif 


// TODO: sict namespace

// TODO: define the structure CellPhone in the sict namespace

// TODO: declare the function display(...),
//         also in the sict namespace