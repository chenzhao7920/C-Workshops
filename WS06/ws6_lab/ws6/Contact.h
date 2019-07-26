//workshop 6 in_lab
//Student Name: Chen Zhao
//Student No.: 120122189
//Section:SAA

//namespace 
namespace sict {
	const int max_name_size = 16;
	//class declaration
	class Contact
	{
		char name[max_name_size+1];
		long long int* phone;
		int amt;

	public:
		Contact();
		Contact(const char*, const long long int*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};

}
 