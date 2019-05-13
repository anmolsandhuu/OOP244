#include <iostream>
#include <cstring>
#include "Hero.h"

namespace sict {

	
	Hero::Hero() {

		name[0] = '\0';
		hp = 0;
		as = 0;


	}

	Hero::Hero(const char *name2, int hp2, int as2) {

		strncpy(name, name2, 41);
		name[41] = '\0';

		hp = hp2;

		as = as2;
		
	}

	Hero::~Hero() {

	}
	
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			hp = hp - attack;

			if (hp < 0) {

				hp = 0;
			}
		}
				
	}

	bool Hero::isAlive() const {
		if (hp == 0) return false;
		else return true;

	}

	int Hero::attackStrength() const {
		if (name[0] == '\0' && as == 0) {

			return 0;
		}

		
		else {
		
			int a = as;
			return a;
		}

		
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) {

		if (hero.name[0] != '\0' && hero.as != 0) {

			for (unsigned int i = 0; i < strlen(hero.name); i++) {
				
				os << hero.name[i];
								
			}
			return os;
		}
		else {
			os << "No hero" << std::endl;
			return os;
		}

		


	}

	const Hero& operator*(const Hero& first, const Hero& second) {

		

		std::cout << "Ancient Battle! ";
		std::cout << first;
		std::cout << " vs ";
		std::cout << second;
		std::cout << " : ";
	

		
		
		Hero temp1 = first;
		Hero temp2 = second;

		int attack1 = temp1.attackStrength();
		int attack2 = temp2.attackStrength();
	

		for (int i = 0; i < max_rounds; i++) {

			temp1 -= attack2;
			temp2 -= attack1;
						
			if (!temp1.isAlive() && !temp2.isAlive()) {
				std::cout << "Winner is ";
				std::cout << first;
				std::cout << " in ";
				std::cout << i + 1;
				std::cout << " rounds." << std::endl;
				return first;
				break;
			}

			else if (!temp1.isAlive()) {
				std::cout << "Winner is ";
				std::cout << second;
				std::cout << " in ";
				std::cout << i+1;
				std::cout << " rounds." << std::endl;
				return second;
				
				break;

			}
			else if (!temp2.isAlive()) {
				std::cout << "Winner is ";
				std::cout << first;
				std::cout << " in ";
				std::cout << i + 1;
				std::cout << " rounds." << std::endl;
				return first;
				
				break;
			}
			

		}


		std::cout << "Winner is ";
		std::cout << first;
		std::cout << " in ";
		std::cout << max_rounds;
		std::cout << " rounds." << std::endl;
		return first;
		
		
	}



	
}

