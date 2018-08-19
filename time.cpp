#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include "time.h"

/* tc - a Time Calculator in the spirit of `bc'
 *
 * by Daniel Lyons <fusion@storytotell.org>
 * RCS information: $Id: time.cpp,v 1.2 2003/11/07 07:03:43 fusion Exp fusion $
 *
 * This program is covered under the terms of the GNU GPL.
 */

void Time :: correct()
{
	while (minute < 0 && hour > 0)
	{
		hour--;
		minute += 60;
	}

	while (minute > 59)
	{
		hour++;
		minute -= 60;
	}
}

Time :: Time (int hours, int minutes)
{
	hour = hours;
	minute = minutes;
	correct();
}

Time :: Time (const char *time_val)
{
	char *minutes, *timespec = strdup(time_val);
	int timespeclen = strlen(timespec);

	for (minutes = timespec; minutes < (timespec + timespeclen); minutes++)
	{
		if (*minutes == ':')
		{
			*minutes++ = '\0';
			break;
		}
	}

	if (minutes == (timespec + timespeclen))
		throw "Bad Time Spec";

	this->hour = atoi(timespec);
	this->minute = atoi(minutes);
	correct();
}

inline Time& Time :: operator+= (Time right)
{
	hour += right.hours();
	minute += right.minutes();
	correct();

	return *this;
}

inline Time& Time :: operator-= (Time right)
{
	hour -= right.hours();
	minute -= right.minutes();
	correct();

	return *this;
}

Time operator+ (const Time left, const Time right)
{
	Time t = left;
	return t += right;
}

Time operator- (const Time left, const Time right)
{
	Time t = left;
	return t -= right;
}

ostream& operator<< (ostream &o, const Time &t)
{
	return o << t.hours() << ':' << setw(2) << setfill('0') << t.minutes();
}

