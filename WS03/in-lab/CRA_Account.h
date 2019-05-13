#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H


namespace sict {
	
	const int max_name_length = 40;
	const int min_sin= 100000000;
	const int max_sin =999999999;

	class CRA_Account


	{


	public:
		void set(const char* familyName, const char* givenName, int sin);

		bool isEmpty() const;

		void display() const;


	private:
		char fname[max_name_length];
		char gname[max_name_length];
		int sin;
	};

}




#endif


