#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exit with code 97, 98, 99, or 100 on failure
 */
int main(int argc, char **argv)
{
	int file_from, file_to, r, w, c;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	file_from = open(argv[1], O_RDONLY);
	if (file_from < 0)
		dprintf(STDERR_FILENO, "Error:Can't read from file%s\n", argv[1]), exit(98);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to < 0)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((r = read(file_from, buffer, 1024)) > 0)
	{
		w = write(file_to, buffer, r);
		if (w < 0)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}

	if (r < 0)
		dprintf(STDERR_FILENO, "Error:Can't read from file%s\n", argv[1]), exit(98);

	c = close(file_from);
	if (c < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

	c = close(file_to);
	if (c < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

	return (0);
}

