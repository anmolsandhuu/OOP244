#ifndef _SUPERHERO_H_
#define _SUPERHERO_H_
#include <iostream>
#include "Hero.h"

namespace sict {
	
	class SuperHero : public Hero {
		int bonus;
		int defence;

	public:
		//constructors & deconstructor
		SuperHero();
		SuperHero(const char *_name, int _health, int _attack, int _bonus, int _defence);
		~SuperHero();
		//member functions
		int attstrength() const;
		int defend() const;

	};
	//helper operator
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}




#endif 
