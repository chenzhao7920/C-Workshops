// TODO: insert header files
#include <iostream>
#include "Fraction.h"

// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		n = 0;
		d = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n_, int d_) {
		bool valid = n_ >= 0 && d_ > 0;
		if (valid) {
			n = n_;
			d = d_;
			reduce();
		}
		else {
			*this = Fraction();
		}
	}
	//destructor

	Fraction::~Fraction() {
	};
	// TODO: implement the max query
	int Fraction::max() const {
		int r;
		r = n >= d ? n : d;
		return r;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		int r;
		r = n < d ? n : d;
		return r;

	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}
	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int g_c_d = 1;
		g_c_d = gcd();
		n = n / g_c_d;
		d = d / g_c_d;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		bool empty = isEmpty();
		Fraction F;
		if (empty) {
			cout << "no fraction stored";
		}
		else {
			F.n = n;
			F.d = d;

			if (F.d == 1) {
				cout << F.n;
			}
			else {
				cout << F.n << '/' << F.d;
			}
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool empty = (d == 0 && n == 0);
		return empty;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+ (const Fraction& rhs) const {
		Fraction tmp;
		bool valid = true;
		if (isEmpty() || rhs.isEmpty())
			valid = false;
		if (valid) {

			tmp.n = n * rhs.d + d * rhs.n;
			tmp.d = d * rhs.d;

		}
		else {
			tmp = Fraction();
		}
		return tmp;
	}
	// TODO: implement the * operator
	Fraction Fraction::operator* (const Fraction& rhs) const {
		Fraction tmp;
		bool valid = true;
		if (isEmpty() || rhs.isEmpty())
			valid = false;
		if (valid) {
			tmp.n = n * rhs.n;
			tmp.d = d * rhs.d;
		}
		else {
			tmp = Fraction();
		}
		return tmp;
	}

	bool Fraction::operator== (const Fraction& rhs) const {

		bool valid = true;
		if (isEmpty() || rhs.isEmpty())
			valid = false;
		if (valid) {
			if (n != rhs.n || d != rhs.d)
				valid = false;
		}
		return valid;
	}
	bool Fraction::operator!= (const Fraction& rhs) const {

		bool valid = true;
		if (isEmpty() || rhs.isEmpty())
			valid = false;
		if (valid) {
			if (n == rhs.n && d == rhs.d)
				valid = false;
		}
		return valid;
	}

	Fraction& Fraction::operator+= (const Fraction& rhs) {
		bool valid = true;
		if (isEmpty() || rhs.isEmpty())
			valid = false;

		if (valid) {
			n = n * rhs.d + d * rhs.n;
			d = d * rhs.d;
		}
		else {
			*this = Fraction();
		}
		return *this;
	}
}