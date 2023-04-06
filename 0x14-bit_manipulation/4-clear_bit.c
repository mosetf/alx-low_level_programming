#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the number containing the bit to be cleared
 * @index: index of the bit to be cleared.
 * Return: 1 if it worked else -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n &= ~(1UL << index);

	return (1);
}
