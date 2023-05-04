#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the number to be modified
 * @index: index, starting from 0 of the bit to set
 * Return: 1 if it worked else -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (!n || index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n |= (1 << index);
	return (1);
}
