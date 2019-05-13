#include <iostream>
#include "CRA_Account.h"
#include <cstring>

using namespace std;




namespace sict {

	void CRA_Account::set(const char* a, const char* b, int c) {
	

		if (c <= max_sin && c >= min_sin) {

			strncpy(fname, a, (strlen(a))); 
			
			strncpy(gname, b, (strlen(b)+1));	

			sin = c;

		}
		else {

			sin = 1;

		}


	}

	bool CRA_Account::isEmpty() const {

		if (sin == 1) {
			return true;
		}
		else
			return false;

	}
	void CRA_Account::display() const {

		if (isEmpty()) {

			cout << "Account object is empty!" << endl;
			
		}
		else {
			cout << "Family Name: " << fname << endl;

			cout << "Given Name : " << gname << endl;

			cout << "CRA Account: " << sin << endl;

		}
			


	}

}