#include <iostream>
#include "time.h"

using namespace std;

/* tc - a Time Calculator in the spirit of `bc'
 *
 * by Daniel Lyons <fusion@storytotell.org>
 * RCS information: $Id: timetest.cpp,v 1.2 2003/11/07 07:03:43 fusion Exp fusion $
 *
 * This program is covered under the terms of the GNU GPL.
 */

int main()
{
	string s;

	cout << "Enter a time: " << endl;
	cin >> s;
	Time t(s.c_str());

	cout << "Enter another time: " << endl;
	cin >> s;
	Time r(s.c_str());

	cout << t << " + " << r << " = " << t + r << endl;
	cout << t << " - " << r << " = " << t - r << endl;

	return 0;
}
