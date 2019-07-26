//Student Name:Chen Zhao
//Student Id:120122189
//Section: SAA

#ifndef _SICT_HERO_H_
#define _SICT_HERO_H_

//my namespace
namespace sict {
	//const variable
	const int max_name_size = 40;
	const int max_roungs = 100;

	class Hero
	{
	protected:
		char name[max_name_size + 1];
		int health;
		int strength;
	
	public:
		
		Hero();
		Hero(const char*, int, int);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		bool isEmpty() const;
		//friend function
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	//non-friend function
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif 
