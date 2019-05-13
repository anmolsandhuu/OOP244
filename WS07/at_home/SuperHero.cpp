#include <iostream>
#include <cstring>
#include "Hero.h"
#include "SuperHero.h"

using namespace std;
namespace sict 
{
	SuperHero::SuperHero() :Hero() 
	{
		bonus = 0;
		defence = 0;
	}

	SuperHero::SuperHero(const char *_name, int _health, int _attack, int _bonus, int _defence) :Hero(_name, _health, _attack) {
		bonus = _bonus;
		defence = _defence;

	}
	SuperHero::~SuperHero() {

	}
	int SuperHero::attstrength() const {
		int a = Hero::attstrength();

		if (a != 0) {
			a += bonus;
		}

		return a;

	}

	int SuperHero::defend() const {
		if (defence == 0) {
			return 0;
		}
		else {
			return defence;
		}


	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {

		std::cout << "Super Fight! ";
		std::cout << first;
		std::cout << " vs ";
		std::cout << second;
		std::cout << " : ";

		SuperHero temp = first;
		SuperHero temp_ = second;

		int attack1 = temp.attstrength() - temp_.defend();
		int attack2 = temp_.attstrength() - temp.defend();


		for (int i = 0; i < max_rounds; i++) {

			temp -= attack2;
			temp_ -= attack1;
			
			if (!temp.isAlive() && !temp_.isAlive()) {
				std::cout << "Winner is "<< first << " in "<< i + 1<< " rounds." << endl;
				return first;
				break;
			}
	
			else if (!temp.isAlive()) {
				std::cout << "Winner is "<< second << " in "<< i + 1<< " rounds." <<endl;
				return second;

				break;

			}
			else if (!temp_.isAlive()) {
				std::cout << "Winner is " << first << " in "<< i + 1 << " rounds." << endl;
				return first;

				break;
			}


		}
		std::cout << "Winner is "<< first << " in " << max_rounds << " rounds."<<endl;
		return first;


	}

}