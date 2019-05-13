#include <iostream>
#include "Data.h"

using namespace std;
namespace sict {

	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) 
	{
		
		cout.precision(2);
		cout << "Population change from " 
			<< min(year, n) << " to " 
			<< max(year, n) << " is " 
			<< fixed
			<< (population[n - 1] - population[0]) / 1000000.00 
			<< " million" << endl;

		cout << "Violent Crime trend is ";
		if (violentCrimeRate[1] - violentCrimeRate[0] > 0)
		{
			cout << "up";
		}
		else
			cout << "down";
		cout << endl;


		cout << "There are " 
			<< fixed 
			<< average(grandTheftAuto, n) / 1000000.00 
			<< " million Grand Theft Auto incidents on average a year" 
			<< endl;


		int mini = min(violentCrimeRate, n);
		int maxin = max(violentCrimeRate, n);

		cout << "The Minimum Violent Crime rate was " << mini << endl;
		cout << "The Maximum Violent Crime rate was " << maxin << endl;


	}
}