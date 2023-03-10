#include <stdio.h>

/**
 * main - returns program name
 * @argc: number of arguments
 * @argv: array of arguments
 * return: program name
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
