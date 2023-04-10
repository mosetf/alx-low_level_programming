#include "main.h"
/**
 * main - duplicates a file
 * @argc: int
 * @argv: double pointer
 * Return: file duplicate
 */

int main(int argc, char **argv)
{
	int fp, fp2, filecheck;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	fp = open(argv[1], O_RDONLY);
	if (fp == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fp2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fp2 == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	while ((filecheck = read(fp, buffer, 1024)) > 0)
	{
		if (filecheck == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		filecheck = write(fd2, buffer, filecheck);
		if (filecheck == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (filecheck == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(fp) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fp %d\n", fp), exit(100);
	if (close(fp2) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fp %d\n", fp2), exit(100);

	return (0);
}
