#include <stdio.h>

/**
 * main - prints the size of various types based on 
 * the computer it is compiled and run on..
 * Return: Always 0.
 */

int main(void)

{
	printf("size of char: %zu byte(s)\n", sizeof(char));
	printf("size of an int: %zu byte(s)\n", sizaof(int));
	printf("size of a long int: %zu byte(s)\n", sizeof(long int));
	printf("size of a long long int: %zu byte(s)\n",sizeof(long long int));
	printf("size of a float %zu byte(s)\n", sizeof(float));
	return (0);
}
