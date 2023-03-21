#include "main.h"

/**
 *  _abs - this program checks for absolute value
 *
 *  @a: this is the parameter to be checked
 *
 *  Return: always a
 */

int _abs(int a)
{
	if (a < 0)
		a = -(a);
	else if (a >= 0)
		a = a;
	return (a);
}
