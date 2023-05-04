#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to get the bit from
 * @index: index of the bit to retrieve, starting from 0
 *
 * Return: the value of the bit at the given index, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n >> index) & 1);
}
