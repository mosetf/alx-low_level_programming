#include "function_pointers.h"
#include <stdlib.h>
/**
 * print_name - prints name
 * @name: string to add
 * @f: pointer to function
 * Return: null
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || == NULL)
		return;

	f(name)
}

