#include "main.h"
#include <string.h>

/**
 * create_file - This function creates a file with the specified filename
 * and it writes the provided text content to it.
 * @filename:  This is the name of the file to create.
 * @text_content:This is the name of the text content to write to the file
 *
 * Return: This function returns  1 on success, -1 on failure
 * (file cannot be created, file cannot be written, write "fails").
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;


	if (filename == NULL)
		return (-1);


	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		
		bytes_written = write(fd, text_content, strlen(text_content));

		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

