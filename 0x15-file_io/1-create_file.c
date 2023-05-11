#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * create_file - This function creates a file.
 * @filename: This represents the pointer to the name of the file to create.
 * @text_content: This represents the pointer to a string to write to the file.
 *
 * Return: This function returns 1 if sucessful ,Otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int fdes, o, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fdes = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	o = write(fdes, text_content, len);

	if (fdes == -1 || o == -1)
		return (-1);

	close(fdes);

	return (1);
}
