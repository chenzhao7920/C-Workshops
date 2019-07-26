//Student Name:Chen Zhao
//Student Id:120122189
//Section: SAA#pragma once

#ifndef _SICT_SUPERHERO_H_
#define _SICT_SUPERHERO_H_
#include "Hero.h"
namespace sict {
	class SuperHero: public Hero{
	 
		int Bonus;
		int Defend;
	public:
		SuperHero();
		SuperHero(const char*, int, int, int b_ = 0, int d_= 0);
		int attackStrength() const;
		int defend() const;
		void attacked(int , int);
	};
	
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif