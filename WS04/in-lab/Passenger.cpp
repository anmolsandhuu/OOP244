// TODO: add file header comments here

// TODO: add your headers here
#include <iostream>
#include "Passenger.h"
#include <cstring>
#include <string.h>
using namespace std;

// TODO: continue your namespace here
namespace sict
{
	// TODO: implement the default constructor here
	Passenger::Passenger()
	{
		EmptyState();
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *Name, const char *Destination) {


		if (Name == NULL || Destination == NULL)
		{
			EmptyState();
		}
		else {
			strncpy(m_name, Name, 32);
			strncpy(m_destination, Destination, 32);
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty()const {
		bool check;
		if (strlen(m_name) == 0 || strlen(m_destination) == 0)
		{
			check = true;
		}
		else
		{
			check = false;
		}
		return check;
	}

		// TODO: implement display query here
	void Passenger::display()const
	{
		if (m_name[0] == '\0' && m_destination[0] == '\0')
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << m_name << " - " << m_destination << endl;
		}
	}


		void Passenger::EmptyState()
		{
			strcpy(m_name, "\0");
			strcpy(m_destination, "\0");
		}
}
