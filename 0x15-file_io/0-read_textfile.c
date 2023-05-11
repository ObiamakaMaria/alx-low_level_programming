#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/**
 * read_textfile- This function reads a text file and print it
 * to the POSIX standard output.
 * @filename: This represent the text file being read
 * @letters: This represent the number of letters to be read
 * Return:This function returns the actual number of bytes read and
 * printed if sucessful   or 0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;

	ssize_t fdes;

	ssize_t q;

	ssize_t r;

	fdes = open(filename, O_RDONLY);
	if (fdes == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	r = read(fdes, buffer, letters);

	q = write(STDOUT_FILENO, buffer, r);

	free(buffer);
	close(fdes);
	return (q);
}
