// Final Project Milestone 1
//
// Version 1.0
// Date 2018/July/13
// Author Anmol Sandhu
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name Anmol Sandhu   Date  2018/July/12    Reason assignment
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Date.h"

namespace AMA
{

	Date::Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
		_cd = 0;
		_es = NO_ERROR; //NO_ERROR = 0 in .h
	}

	Date::Date(int y, int m, int d) 
	{
		_year = y;
		_month = m;
		_day = d;
		_cd = _year * 372 + _month * 13 + _day;

		if (_year == 0 && _month == 0 && _day == 0)
			errCode(CIN_FAILED);
		else if (_year < min_year || _year > max_year)
			errCode(YEAR_ERROR);
		else if (_month < 1 || _month > 12)
			errCode(MON_ERROR);
		else if (_day < 1 || _day > mdays(_month, _year))
			errCode(DAY_ERROR);
		else
			errCode(NO_ERROR);

		if (bad()) {
			_year = 0;
			_month = 0;
			_day = 0;
			_cd = 0;
		}
	}
	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode) 
	{
		_es = errorCode;
	}

	int Date::errCode() const 
	{
		return _es;
	}

	bool Date::bad() const 
	{
		if (_es == NO_ERROR)
			return false;
		else
			return true;
	}

	bool Date::operator==(const Date& rhs) const
	{
		return _cd == rhs._cd && _cd != 0 && rhs._cd != 0;
	}

	bool Date::operator!=(const Date& rhs) const
	{
		return _cd != rhs._cd && _cd != 0 && rhs._cd != 0;
	}

	bool Date::operator<(const Date& rhs) const
	{
		return _cd < rhs._cd && _cd != 0 && rhs._cd != 0;
	}

	bool Date::operator>(const Date& rhs) const
	{
		return _cd > rhs._cd && _cd != 0 && rhs._cd != 0;
	}

	bool Date::operator<=(const Date& rhs) const
	{
		return _cd <= rhs._cd && _cd != 0 && rhs._cd != 0;
	}

	bool Date::operator>=(const Date& rhs) const
	{
		return _cd >= rhs._cd && _cd != 0 && rhs._cd != 0;
	}

	std::istream& Date::read(std::istream& istr)
	{
		int y, m, d;

		istr >> y;
		istr.ignore();
		istr >> m;
		istr.ignore();
		istr >> d;

		Date temp(y, m, d);

		if (temp._year == 0 || temp._month == 0 || temp._day == 0)
		{
			*this = Date();
			errCode(temp._es);
		}
		else
		{
			this->_year = temp._year;
			this->_month = temp._month;
			this->_day = temp._day;
		}

		if (istr.fail() == true)
		{
			this->_es = CIN_FAILED;
		}

		return istr;

	}

	std::ostream& Date::write(std::ostream& ostr) const
	{
		char RemoveChar = '/';


		ostr << this->_year;
		ostr << RemoveChar;

		ostr.width(2);
		ostr.fill('0');
		ostr << this->_month;
		ostr << RemoveChar;

		ostr.width(2);
		ostr.fill('0');
		ostr << this->_day;
		ostr.fill(' ');
		return ostr;
	}


	std::ostream& operator<<(std::ostream& ostr, const Date& d) {
		return d.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Date& d) {
		return d.read(istr);
	}

}
