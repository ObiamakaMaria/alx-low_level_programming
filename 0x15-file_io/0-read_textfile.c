#include "main.h"


/**
 * read_textfile -This function reads a text file and print it to the
 * POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: This function returns the actual number of letters read and
 * printed on success,and 0 if the file cannot be opened or read, or
 * if write fails or does not write the expected amount of bytes.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, letters_read;
	char *buffer;
	ssize_t letters_written;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = (char *)malloc(letters + 1);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	letters_read = read(fd, buffer, letters);
	if (letters_read == -1)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	if (letters_read > 0)
	{
		letters_written = write(STDOUT_FILENO, buffer, letters_read);

		if (letters_written == -1 || letters_written != letters_read)
		{
			letters_written = 0;
		}
	}

	close(fd);
	free(buffer);
	return (letters_written);
}

