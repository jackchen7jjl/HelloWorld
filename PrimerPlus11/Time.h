#pragma once
#ifndef TIME_H_
#define TIME_H_

class Time
{
private:
	int _hour;
	int _minute;

public:
	Time();
	Time(int hour, int minute);

	void addMinutes(int minute);
	void show();
	Time operator+(const Time &t) const;
	friend Time operator*(double m, const Time &t);
};

#endif // !_TIME_