#include "CRA_Account.h"
namespace sict {
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		


		if (sin >= min_sin && sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
			


			int isin[9];
			int checkDigit;
			int Alternates[4];
			int other[4];
			int alternateSums[4];
			int otherAlternateSum = 0;
			int asum = 0;
			

 
			for (int i = 9 - 1; i >= 0; i--) {
				int y = (int)pow(10, i);
				int z = sin / y;
				int x = sin / (y * 10);

				isin[9 - (i + 1)] = z - x * 10;
			}
			
			checkDigit = isin[8];
			
			
			int tmpCount = 0;
			for (int i = 7; i >= 0; i -= 2)
			{
				Alternates[tmpCount] = isin[i];
				tmpCount++;
			}
			
			tmpCount = 0;
		

			for (int i = 6; i >= 0; i -= 2)
			{
				other[tmpCount] = isin[i];
				tmpCount++;
			}

			
			for (int i = 0; i < 4; i++)
			{
				alternateSums[i] = Alternates[i] + Alternates[i];
				otherAlternateSum += other[i];
			}

			
			for (int i = 0; i < 4; i++)
			{
				int copy = alternateSums[i];

				while (copy > 0)
				{
					asum += copy % 10;
					copy /= 10;
				}
			}

			
			asum += otherAlternateSum;

			if (abs(asum - ((10 - asum % 10) + asum)) == checkDigit)
			{
				strncpy(family_name, familyName, max_name_length);
				strncpy(given_name, givenName, max_name_length);
				CRA_Account::sin = sin;
				numYears = 0;
			}
			else 
			{
				CRA_Account::sin = 0;
			}
		}
		else {
			CRA_Account::sin = 0;
		}
	}

	void CRA_Account::set(int year, double balance) {
		if (!isEmpty() && numYears != max_years) {
			taxReturn[numYears] = year;
			CRA_Account::balance[numYears] = balance;
			numYears++;
		}
	}

	bool CRA_Account::isEmpty() const {
		return CRA_Account::sin == 0 ? true : false;
	}

	void CRA_Account::display() const {
		if (!isEmpty()) {
			std::cout << "Family Name: " << family_name << std::endl;
			std::cout << "Given Name : " << given_name << std::endl;
			std::cout << "CRA Account: " << CRA_Account::sin << std::endl;

		
			for (int i = 0; i < numYears; i++)
			{
				if (balance[i] > 2)
				{
					std::cout << "Year (" << taxReturn[i] << ") balance owing: " << std::fixed << std::setprecision(2) << balance[i] << std::endl;
				}
				else if (balance[i] < -2)
				{
					double bal = fabs(balance[i]);
					std::cout << "Year (" << taxReturn[i] << ") refund due: " << std::fixed <<std::setprecision(2) << bal << std::endl;
				}
				else
					std::cout << "Year (" << taxReturn[i] << ") No balance owing or refund due!" << std::endl;
			}
		}
		else {
			std::cout << "Account object is empty!" << std::endl;
		}
	}
}