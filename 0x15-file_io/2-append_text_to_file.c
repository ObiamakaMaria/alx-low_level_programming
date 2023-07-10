#include "main.h"
#include <string.h>

/**
 * append_text_to_file - This function appends text at the
 * end of a file.
 * @filename:  This is the name of the file.
 * @text_content:  This is the text content to append.
 *
 * Return: This function returns  1 on success, -1 on failure.
 */


int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t letters_written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{

		letters_written = write(fd, text_content, strlen(text_content));

		if (letters_written == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
