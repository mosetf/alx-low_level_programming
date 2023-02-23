#include "main.h"

/**
 *print_line - draws straight line
 *@n: number of lines to draw
 *Return: prinnt \n of n is o or less
 */

void print_line(int n)
{
	int m;

	if (n <= 0)
	{
	_putchar('\n');
	}
	else
	{
	for (m = 0; m < n; m++)
	{
	_putchar(95);
	}
	_putchar('\n');
	}
}
