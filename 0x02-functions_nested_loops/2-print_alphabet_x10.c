#include "main.h"

/**
 * main - entry point 
 * Return: Void 
 */

void print_alphabet_x10(void)
{
	char x;
	int i = 0;
	while (i<9)
	{
		for (x = '0'; x <= 'z'; x++)
	{
	_putchar(x);
	}
	_putchar('\n');
	i++;
	}
}
