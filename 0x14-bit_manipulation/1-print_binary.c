#include "main.h"
/**
 *print_binary - prints base 2 of a number
 *RETURN: binary number
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int i, j;

	for (i = 63; i >= 0; i--)
	{
		j = n >> i;
		if (j & mask)
			_putchar('1');
		else if (!(j & mask) && (i == 0 || (n << 1) == 0))
			_putchar('0');
	}
}
