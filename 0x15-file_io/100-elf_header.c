#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>
#include <stdarg.h>

void print_error(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	fprintf(stderr, "Error: ");
	vfprintf(stderr, format, args);
	fprintf(stderr, "\n");

	va_end(args);
}


void print_error_exit(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	print_error(format, args);

	va_end(args);

	exit(1);
}



void print_elf_header_info(const Elf64_Ehdr *elf_header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:");
	for (i = 0; i < EI_NIDENT; i++)
		printf(" %02x", elf_header->e_ident[i]);
	printf("\n");

	printf("  Class:                             ");
	switch (elf_header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}

	printf("  Data:                              ");
	switch (elf_header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}

	printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (elf_header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
			/* Add more OS/ABI cases as needed */

		default:
			printf("Unknown\n");
			break;
	}

	printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (elf_header->e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
			/* Add more e_type cases as needed */

		default:
			printf("Unknown\n");
			break;
	}

	printf("  Entry point address:               0x%lx\n", elf_header->e_entry);
}


int main(int argc, char *argv[])
{
	const char *filename;
	Elf64_Ehdr elf_header;
	int fd;
	ssize_t bytes_read;


	if (argc != 2)
	{
		print_error("Invalid number of arguments. Usage: elf_header elf_filename");
		return (1);
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		print_error("Failed to open file");
		return (1);
	}

	bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));

	if (bytes_read != sizeof(Elf64_Ehdr))
	{
		print_error("Failed to read ELF header");
		close(fd);
		return (1);
	}

	if (!(elf_header.e_ident[EI_MAG0] == ELFMAG0 &&
				elf_header.e_ident[EI_MAG1] == ELFMAG1 &&
				elf_header.e_ident[EI_MAG2] == ELFMAG2 &&
				elf_header.e_ident[EI_MAG3] == ELFMAG3))
	{
		print_error("Not an ELF file");
		close(fd);
		return (1);
	}

	print_elf_header_info(&elf_header);

	close(fd);
	return (0);
}
