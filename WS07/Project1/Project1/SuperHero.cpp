//Student Name:Chen Zhao
//Student Id:120122189
//Section: SAA
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "SuperHero.h"

namespace sict {
    //public function
	SuperHero::SuperHero() {
		//derived class non argument constructor call bass class constructor automicly
		Bonus = 0;
		Defend = 0;
	}
	SuperHero::SuperHero(const char* n_, int h_, int s_, int b_, int d_):Hero(n_, h_, s_){
		bool valid = (b_ > 0 && d_ > 0);
		if (valid) {
			Bonus = b_;
			Defend = d_;
		}
		else {
			Bonus = 0;
			Defend = 0;
		}
	}
	int SuperHero::attackStrength() const {
	//	return Bonus + Hero::attackStrength();
   //if base class data member has key word protected; then its derived classes could use it private data member
		return Bonus + strength;
	}
	int SuperHero::defend() const {
		int r;
		if (strcmp(name, "?") == 0)
			r = 0;
		else
			r = Defend;
		return r;
	}

	void SuperHero::attacked(int attack, int defend) {
		health = (health - attack + defend);
	}

	//non-friend helper function
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero left = first;
		SuperHero right = second;
		bool fight = true;
 
			for (int i = 1; i <= max_roungs && fight; i++) {
				//superhero fight
				left.attacked(right.attackStrength(), left.defend());
				right.attacked(left.attackStrength(), right.defend());
				
				//check if have winner, no winner then keep fight
				if (left.isAlive() && (!right.isAlive())) {
					fight = false;
					std::cout << "Super Fight! " << first << " vs " << second << " : Winner is " << first << " in " << i << " rounds." << std::endl;
				}
				else if ((!left.isAlive()) && (!right.isAlive())) {
					fight = false;
					std::cout << "Super Fight! " << first << " vs " << second << " : Winner is " << first << " in " << i << " rounds." << std::endl;
				}
				else if ((!left.isAlive()) && (right.isAlive())) {
					fight = false;
					std::cout << "Super Fight! " << first << " vs " << second << " : Winner is " << second << " in " << i << " rounds." <<std::endl;
				}
			}
	//	}
		
	    return (left.isAlive()) ? first : second;
	}

}