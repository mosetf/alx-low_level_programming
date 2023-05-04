#include "main.h"

/**
 * flip_bits - Returns the no of bits you would need to flip to get from
 * one no to the next
 * @n: 1st no
 * @m: 2nd no
 * Return: no of flips needed to flip from one no to next no
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bits = n ^ m;
	unsigned int count = 0;

	while (bits > 0)
	{
		if (bits & 1)
			count++;
		bits >>= 1;
	}

	return (count);
}
