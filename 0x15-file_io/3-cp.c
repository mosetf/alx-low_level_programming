#include "main.h"
#define BUFFER_SIZE 1024

/**
* error - Prints an error message and exits with the specified code
* @message: The error message format string
* @arg: The argument to be substituted in the format string
* @code: The exit code
*/
void error(char *message, char *arg, int code)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
* main - Copies the content of a file to another file
* @argc: The argument count
* @argv: The argument vector
*
* Return: 0 on success, a positive integer on failure
*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to, n_read, n_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		error("Usage: %s file_from file_to\n", argv[0], 97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		error("Error: Can't read from file %s\n", argv[1], 98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		error("Error: Can't write to file %s\n", argv[2], 99);
	}
	while ((n_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		n_written = write(fd_to, buffer, n_read);
		if (n_written != n_read)
		{
			error("Error: Can't write to file %s\n", argv[2], 99);
		}
	}
	if (n_read == -1)
	{
		error("Error: Can't read from file %s\n", argv[1], 98);
	}
	if (close(fd_from) == -1)
	{
		error("Error: Can't close fd %d\n", fd_from, 100);
	}
	if (close(fd_to) == -1)
	{
		error("Error: Can't close fd %d\n", fd_to, 100);
	}

	return (0);
}
