
Nestrelda-2023
/
alx-low_level_programming
Public
Code
Issues
Pull requests
Actions
Projects
Security
Insights
Beta Try the new code view
alx-low_level_programming/0x15-file_io/2-append_text_to_file.c
@Nestrelda-2023
Nestrelda-2023 Create 2-append_text_to_file.c
 1 contributor
33 lines (26 sloc)  695 Bytes
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 * Return: If the function fails or filename is NULL - -1.
 * If the file does not exist the user lacks write permissions - -1.
 * Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
