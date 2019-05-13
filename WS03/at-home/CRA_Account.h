#ifndef _CRA_ACCOUNT_H
#define _CRA_ACCOUNT_H
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <math.h>

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_years = 4;

	class CRA_Account {
		char family_name[max_name_length];
		char given_name[max_name_length];
		int sin; 
		int taxReturn[max_years]; 
		double balance[max_years]; 
		int numYears = 0; 
	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
	};
}
#endif