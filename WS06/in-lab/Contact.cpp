#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Contact.h"
#include <string.h>

using namespace std;

namespace sict {
	Contact::Contact() {
		m_number = 0;
		m_name[0] = 'e';
		m_name[1] = '\0';
		m_size = 0;
	}
	Contact::Contact(const char *name, const long long phoneNumber[], const int size) {
		int loop = 0;

		if (name == nullptr || name[0] == '\0')
		{
			m_name[0] = 'e';
			m_name[1] = '\0';
		}
		else {
			strncpy(m_name, name, 19);
			m_name[19] = '\0';
		}
		if (phoneNumber != nullptr && size > 0) {
			for (int i = 0; i < size; i++) {
				if (modulus(phoneNumber[i]) == true) {
					loop++;
				}
			}
			m_number = new long long[loop];
			m_size = loop;
			int loop2 = 0;
			for (int i = 0; i < size; i++) {
				if (modulus(phoneNumber[i]) == true) {
					m_number[loop2] = phoneNumber[i];
					loop2++;
				}
			}
		}
		else {
			m_number = 0;
			m_size = -1;
		}


	}
	Contact::~Contact() {
		delete[] m_number;
	}
	bool Contact::isEmpty() const {
		bool check = false;
		if (m_name[0] == 'e') {
			check = true;
		}
		return check;
	}
	void Contact::display() const {

		if (isEmpty() == true) {
			cout << "Empty contact!" << endl;
		}
		else {
			if (strlen(m_name) < 20) {
				cout << m_name << endl;
				if (m_number != 0) {
					for (int i = 0; i < m_size; i++) {
						cout << "(+" << m_number[i] / 10000000000 << ") " << (m_number[i] / 10000000) % 1000
							<< " " << (m_number[i] % 10000000) / 10000 << "-" << (m_number[i] % 10000000) % 10000 << endl;
					}
				}
			}
		}
	}
	bool Contact::modulus(long long phone) {
		long long country;
		long long areaCode;
		long long number;
		bool check = false;
		country = phone / 10000000000;
		areaCode = (phone / 10000000) % 1000;
		number = phone % 10000000;
		if (country > 0 && country <99) {
			if (areaCode > 100 && areaCode < 999) {
				if (number > 1000000 && number < 9999999) {
					check = true;

				}
			}

		}
		return check;
	}


}









