#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << 63;
	int count = 0;

	while (mask > 0)
	{
		if (n & mask)
		{
			_putchar('1');
			count++;
		}
		else if (count > 0)
			_putchar('0');
		mask >>= 1;
	}
	if (count == 0)
		_putchar('0');
}

