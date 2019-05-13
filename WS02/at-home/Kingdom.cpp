/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

#include "Kingdom.h"

namespace sict 
{

    void display(const Kingdom &kingdom)
	{
        cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
    }



    void display(const Kingdom *kingdom, int amount)
	{
        int totalPopulation = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;


        for (int i = 0; i < amount; i++)
        {
            cout << (i + 1) << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
			totalPopulation += kingdom[i].m_population;
        }


		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalPopulation << endl;
		cout << "------------------------------" << endl;
    }
}
