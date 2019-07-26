//Student Name:Chen Zhao
//Student Id:120122189
//Section: SAA
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
namespace sict {
 
	// public function
	//defalte constructor
	Hero::Hero() {
		name[0] = '?';	
		health = 0;
		strength = 0;
	}
	//three parameter constructor
	Hero::Hero(const char* n_, int h_, int s_) {
		bool valid = (n_ != nullptr && h_ >= 0 && s_ >= 0);
		if (valid) {
			strncpy(name, n_, max_name_size);
			name[max_name_size] = '\0';
			health = h_;
			strength = s_;
		}
		else {
			strcpy(name, "?");
			health = 0;
			strength = 0;

		}
	}
	
	//isEmpty, if object in the empty state, the return true
	bool Hero::isEmpty() const{
		if (strcmp(name, "?") == 0 )
			return true;
		else
			return false;
	}
	//operater -= 
	void  Hero::operator-=(int attack) {
		if (attack > 0) {
			health -= attack;
			if (health < 0)
				health = 0;
		}
	}
	//function isAlive,return if it is alive
	bool  Hero::isAlive() const {
		bool alive = health > 0 ? true : false;
		return alive;
	}
	//return the attack strength of the current object, if the object is in a safe empty state, return '0'
	int  Hero::attackStrength() const {
		int str;
		if (isEmpty())
			str = 0;
		else
			str = strength;
		return str;
	}
	//helper function
	//print the name of hero, if hero is empty, print "No hero"
	//helper function in the class could access the private data member otherwise , we need member function
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (hero.isEmpty())
			os << "No hero";
		else
			os << hero.name;
		return os;
	}
	//non-friend function, return the winner of max_rounds battle
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero left=first;
		Hero right=second;
		bool fight = true;
		int left_str = left.attackStrength();
		int right_str = right.attackStrength();
		 
		for (int i = 1; i <= max_roungs && fight; i++) {                   
		 
			left -= right_str;
			right -= left_str;
			
			if (left.isAlive() && (!right.isAlive())) {
				fight = false;
				cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << first << " in " << i << " rounds." << endl;
			}
			else if ((!left.isAlive()) && (!right.isAlive())) {
				fight = false;
				cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << first << " in " << i << " rounds." << endl;
			}
			else if ((!left.isAlive()) && (right.isAlive())) {
				fight = false;
				cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << second << " in " << i << " rounds." << endl;
			}
		 
		} 

		return (left.isAlive()) ? first : second;
	} 
	
}
 