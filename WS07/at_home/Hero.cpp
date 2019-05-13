#include <iostream>
#include <cstring>
#include "Hero.h"

namespace sict {

	
	Hero::Hero() {
		name[0] = '\0';
		health = 0;
		attack = 0;


	}

	Hero::Hero(const char *_name, int _health, int _attack) {

		strncpy(name, _name, 41);
		name[41] = '\0';

		health = _health;

		attack = _attack;
		
	}

	Hero::~Hero() {

	}
	
	void Hero::operator-=(int _attack)\
	{
		if (_attack > 0) {
			health = health - _attack;

			if (health < 0) {

				health = 0;
			}
		}
				
	}

	bool Hero::isAlive() const 
	{
		if (health == 0) return false;
		else return true;

	}

	int Hero::attstrength() const {
		
		if (name[0] == '\0' && attack == 0) {

			return 0;
		}

		
		else {
		
			int a = attack;
			return a;
		}

		
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		
		if (hero.name[0] != '\0' && hero.attack != 0) {

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
	

		
		Hero temp = first;
		Hero temp_ = second;

		int attack1 = temp.attstrength();
		int attack2 = temp_.attstrength();
	

		for (int i = 0; i < max_rounds; i++) {
			
			temp -= attack2;
			temp_ -= attack1;	
			if (!temp.isAlive() && !temp_.isAlive()) {
				std::cout << "Winner is ";
				std::cout << first;
				std::cout << " in ";
				std::cout << i + 1;
				std::cout << " rounds." << std::endl;
				return first;
				break;
			}
			
			else if (!temp.isAlive()) {
				std::cout << "Winner is ";
				std::cout << second;
				std::cout << " in ";
				std::cout << i+1;
				std::cout << " rounds." << std::endl;
				return second;
				
				break;

			}
			else if (!temp_.isAlive()) {
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

