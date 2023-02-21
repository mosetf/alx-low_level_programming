#include "main.h"

/**
 * print_alphabet_x10 - make alphabet x10 times
 * Return: Void
 */

void print_alphabet_x10(void)
{
	char x;
	int i = 0;

	while (i <= 9)
	{
	for (x = '0'; x <= 'z'; x++)
	{
	_putchar(x);
	}
	_putchar('\n');
	i++;
	}
}
