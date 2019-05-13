// TODO: add file header comments here

// TODO: add header file guard here
#pragma once
// TODO: add header file guard here 
#ifndef ICT_PASSENGER_H__
#define ICT_PASSENGER_H__
// TODO: declare your namespace here
using namespace std;
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
	private:
		char m_name[32];
		char m_destination[32];
	public:
		Passenger();
		Passenger(const char *Name, const char *Destination);
		bool isEmpty()const;
		void display()const;
		// additional code for enhancement
		void EmptyState();
	};
}
#endif
