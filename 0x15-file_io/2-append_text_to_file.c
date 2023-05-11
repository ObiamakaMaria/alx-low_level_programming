#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - This function appends text at the end of a file.
 * @filename: This represents the pointer to the name of the file.
 * @text_content:This represents the string to add to the end of the file.
 *
 * Return: This function returns 1 if sucessful   Otherwise - 1.
 * Description: If the file does not exist, and the user lacks  the
 * write permissions return -1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int p, q, len = 0;

	if (filename == NULL)
		return (-1);


	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	p = open(filename, O_WRONLY | O_APPEND);

	q = write(p, text_content, len);

	if (p == -1 || q == -1)
		return (-1);

	close(p);

	return (1);
}
