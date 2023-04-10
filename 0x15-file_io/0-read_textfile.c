#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the text file to be read
 * @letters: the maximum number of letters to be read and printed
 * Return: the actual number of letters read and printed
 *         if the file cannot be opened or read return 0
 *         if filename is null return 0
 *         if write fails the expected amount of bytes return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int al;
	ssize_t alRead, alWrite, alClose;
	char *lineBuffer;

	if (filename == NULL)
		return (0);

	lineBuffer = malloc(sizeof(char) * letters);

	if (lineBuffer == NULL)
		return (-1);

	al = open(filename, O_RDONLY);

	if (al == -1)
		return (0);

	alRead = read(al, lineBuffer, letters);

	if (alRead == -1)
		return (-1);

	alWrite = write(STDOUT_FILENO, lineBuffer, alRead);

	if (alWrite == -1)
		return (-1);
	alClose = close(al);

	if (alClose == -1)
		return (-1);

	return (alRead);
}
