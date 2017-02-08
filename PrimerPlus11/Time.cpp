#include "Time.h"
#include <iostream>
using namespace std;

Time::Time()
{
	_minute = 0;
	_hour = 0;
}

Time::Time(int hour, int minute)
{
	_hour = hour;
	_minute = minute;
}

void Time::addMinutes(int minute)
{
	_minute += minute;
	_hour += _minute / 60;
	_minute = _minute % 60;
}

void Time::show()
{
	cout << "hour: " << _hour << " minute: " << _minute << endl;
}

Time Time::operator+(const Time &t) const
{
	Time ot = Time(_hour, _minute);
	ot._hour += t._hour;
	ot.addMinutes(t._minute);
	return ot;
}

Time operator*(double m,const Time &t)
{
	Time ot = Time(t._hour,t._minute);
	ot._minute *= m;
	ot._hour *= m;
	ot._hour += ot._minute / 60;
	ot._minute = ot._minute % 60;
	return ot;
}