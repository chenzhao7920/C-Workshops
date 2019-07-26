// TODO: header file guard
#ifndef _SICT_FRACTION_H_
#define _SICT_FRACTION_H_
// !_SICT_FRACTION_H_
 
// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction
	{
		// TODO: declare instance variables 
		int n;
		int d;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		~Fraction();
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator 
		Fraction operator+ (const Fraction& rhs) const;
		Fraction operator* (const Fraction& rhs) const;
		bool operator== (const Fraction& rhs) const;
		bool operator!= (const Fraction& rhs) const;
		Fraction& operator+= (const Fraction& rhs);

	};
}

#endif 