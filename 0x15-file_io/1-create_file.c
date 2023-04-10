#include "main.h"
/**
* create_file - creates a file with the given filename and writes the
* contents of the given text to it.
*
* @filename: the name of the file to create
* @text_content: the text to write to the file
*
* Return: 1 on success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
int fd, result, len;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
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
