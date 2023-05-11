#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - This function allocates 1024 bytes for a buffer.
 * @file: This represents the file buffer storing the chars.
 * Return: This function returns the pointer to the newly-allocated buffer.
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file -  This function closes the  file descriptors.
 * @fd: This represents the file descriptor to be closed.
 */

void close_file(int fd)
{
	int e;

	e = close(fd);

	if (e == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main -  This function copies the contents of a file to another file.
 * @argc:  This represents the number of arguments supplied to the program.
 * @argv: This represents an array of pointers to the arguments.
 * Return: 0 on success.
 *
 * Description: This function exit code 97,
 * If the argument count is incorrect.
 * This function exit code 98, If  If file_from does not
 * exist or cannot be read.
 * This function exit code 99, If file_to cannot be created or written to.
 * This function exit code 100, If file_to or file_from cannot be closed.
 */

int main(int argc, char *argv[])
{
	int fr, t, s, q;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
	}

	buffer = create_buffer(argv[2]);

	fr = open(argv[1], O_RDONLY);

	s = read(fr, buffer, 1024);

	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fr == -1 || s == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		q = write(t, buffer, s);
		if (t == -1 || q == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		s = read(fr, buffer, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (s > 0);

	free(buffer);

	close_file(fr);

	close_file(t);

	return (0);
}
