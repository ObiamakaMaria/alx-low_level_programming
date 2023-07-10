#include "main.h"
#include <stdarg.h>


/**
 * Program: cp - This function copies the content of a
 * file to another file.
 *
 * Return: This function returns 0 after sucessful execution.
 */


#define BUFFER_SIZE 1024

void print_error_exit(int exit_code, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);

	va_end(args);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	int fd_from;
	int fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t letters_read, letters_written;

	const char *file_from;
	const char *file_to;

	if (argc != 3)
		print_error_exit(97, "Usage: cp file_from file_to\n");

	file_from = argv[1];
	file_to = argv[2];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error_exit(98, "Error: Can't read from file %s\n", file_from);

fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (fd_to == -1)
		print_error_exit(99, "Error: Can't write to %s\n", file_to);



	while ((letters_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		letters_written = write(fd_to, buffer, letters_read);
		if (letters_written == -1)
			print_error_exit(99, "Error: Can't write to %s\n", file_to);
	}

	if (letters_read == -1)
		print_error_exit(98, "Error: Can't read from file %s\n", file_from);

	if (close(fd_from) == -1)
		print_error_exit(100, "Error: Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		print_error_exit(100, "Error: Can't close fd %d\n", fd_to);

	return (0);
}
