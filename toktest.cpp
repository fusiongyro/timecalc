#include "time.h"
#include "timegram.h"
#include <iostream>

using namespace std;

/* tc - a Time Calculator in the spirit of `bc'
 *
 * by Daniel Lyons <fusion@storytotell.org>
 * RCS information: $Id: toktest.cpp,v 1.2 2003/11/07 07:03:43 fusion Exp fusion $
 *
 * This program is covered under the terms of the GNU GPL.
 */

extern int yylex(void);
Time* yylval;

int main()
{
	int code;

	while ((code = yylex()) != 0)
	{
		switch(code)
		{
			case TIME:
				cout << "TIME " << *(yylval) << endl;
				break;
			case PLUS:
				cout << "PLUS" << endl;
				break;
			case MINUS:
				cout << "MINUS" << endl;
				break;
			case LPAREN:
				cout << "LPAREN" << endl;
				break;
			case RPAREN:
				cout << "RPAREN" << endl;
				break;
			case NEWLINE:
				cout << "NEWLINE" << endl;
				break;
			default:
				cout << "what? " << code << endl;
				break;
		}
	}

	return 0;
}
