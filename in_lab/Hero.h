#ifndef _HERO_H_
#define _HERO_H_
#include <iostream>

namespace sict {
	const int max_rounds = 100;

	class Hero {

		char name[41];
		int hp;
		int as;
		
	public:
		//constructior and destructor
		Hero();
		Hero(const char *a, int b, int c);
		~Hero();

		//member functions
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;

		//friend
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};


	
	const Hero& operator*(const Hero& first, const Hero& second);



}




#endif // !_HERO_H_
