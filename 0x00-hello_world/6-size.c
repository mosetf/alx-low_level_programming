#include <stdio.h>
/**
 * main - prints the size of various types based on 
 * the computer it is compiled and run on..
 * Return: Always 0.
 */
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;

printf("size of char: %lu byte(s)\n",(unsigned long)siz
eof(a));
printf("size of an int: %lu byte(s)\n",(unsigned long)siz
eof(b));
printf("size of a long int: %lu byte(s)\n",(unsigned lo
ng)sizeof(c));
printf("size of a long long int: %lu byte(s)\n", (unsigne
d long)sizeof(d));
printf("size of a float %lu byte(s)\n", (unsigned long)s
izeof(f));
return (0);
}
