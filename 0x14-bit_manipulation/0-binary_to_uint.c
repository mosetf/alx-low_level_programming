#include "main.h"
#include <stddef.h>


/**
 * binary_to_uint - converts base 2 to an unsigned int
 * @b: pointer to a string
 * Return: the converted number
 *		0 if there is more tha 1 char in
 *		the string b that is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (; *b != '\0'; b++)
	{
		if (*b == '0')
			result = (result << 1) | 0;
		else if (*b == '1')
			result = (result << 1) | 1;
		else
			return (0);
	}

	return (result);
}
