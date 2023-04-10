#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file
 * @text_content: the text to add to the file
 * Return: 1 on success -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, result, len;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (len = 0; text_content[len]; len++)
		;
	result = write(fd, text_content, len);
	if (result == -1)
	{
		close(fd);
		return (-1);
	}
	}

	close(fd);

	return (1);
}
