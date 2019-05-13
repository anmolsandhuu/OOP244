#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
namespace sict {
	const int smal_NUM = 0;
	const int col_WIDTH = 15;
	const int larg_NUM = 1000000000; 
	

	template <class T>
	T max(const T* data, int n) 
	{
		T max = smal_NUM;

		for (int i = 0; i < n; i++) 
		{
			max = (data[i] > max) ? data[i] : max;
		}
		return max;
	}

	template <typename T>
	T min(const T* data, int n) 
	{
		T min = larg_NUM;

		for (int i = 0; i < n; i++) 
		{
			min = (data[i] < min) ? data[i] : min;
		}
		return min;
	}

	template <typename T>

	T sum(const T* data, int n) 
	{
		T sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += data[i];
		}
		return sum;
		
	}

	template <typename T>

	double average(const T* data, int n)
	{
		double avg = (sum(data, n) / n);
		return avg;
	}
	
	template <typename T>

	bool read(std::istream& input, T*data, int n)
	{
		for (int i = 0; i < n && input; i++) 
		{
			input.ignore(2000, ',');
			input >> data[i];
			if (!input)
			{
				input.ignore(2000, '\n');
				return false;
			}
		}
		return true;
	}

	template <typename T>
	void display(const char* name, const T* data, int n)
	{
		cout.width(20);
		cout << name;
		for (int i = 0; i < n; i++)
		{
			cout.width(col_WIDTH);
			cout << data[i];
		}
		cout << endl;
	}

	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n)
	{
		char rowname[2000];
		bool ok = !input.bad();


		if (ok)
		{

			input.get(rowname, 2000, ',');
			
			if (std::strcmp(rowname, name) != 0)
			{
				
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			
			ok = read(input, data, n);

	
		input.ignore(2000, '\n');
		return ok;
	}


	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif