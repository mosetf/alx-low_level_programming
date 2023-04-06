#include "main.h"

/**
 * get_bit - returns value of a bit at an index
 * @n: variable to be checked
 * @index: index starting from 0 of the bit
 * RETURN: value of the bit at index or -1 if error occurs
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

			if ((n >> index) & 1)
				return (1);
			else
				return (0);
}
