#include "main.h"

/**
 * binary_to_unit - converts a binary number to an unsigned int
 * @b:pointer to string of 0 and 1 chars
 * Return: the converted number
 */
unsigned int binary_to_unit(const char *b)
{
	if (!b || !*b)
		return (0);

	unsigned int decimal = 0;
	for (; *b; ++b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		decimal = (decimal << 1) | (*b - '0');
	}

	return (decimal);
}

