#include "time.h"
#include "timegram.h"

/* tc - a Time Calculator in the spirit of `bc'
 *
 * by Daniel Lyons <fusion@storytotell.org>
 * RCS information: $Id: tc.cpp,v 1.2 2003/11/07 07:01:08 fusion Exp fusion $
 *
 * This program is covered under the terms of the GNU GPL.
 */

extern int yyparse(void);

int main()
{
	return yyparse();
}
