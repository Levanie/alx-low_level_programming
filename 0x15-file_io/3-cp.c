#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - check description
 * Description: allocates 1024 bytes for buffer
 *
 * @file:name of file
 * Return: pointer
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
 * close_file - check description
 * Description: closes file
 * @fd: file descriptor
 */

void close_file(int fd)
{
	int cl;

	cl = close(fd);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the contents of a file
 * @argc:no of arguments
 * @argv:array f pointers
 * Return: 0
 * Description: if argument count is incorrect- exit code 97
 * if file_from can't be read - exit code 98
 * if file_to can't be written to - exit code 99
 * if file_to or filr_from cant be closed exit code 100
 */

int main(int argc, char *argv[])
{

	int to, from, re, wr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);

	from = open(argv[1], O_RDONLY);

re = read(from, buffer, 1024);

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || re == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
wr = write(to, buffer, re);

if (to == -1 || wr == -1)

		{

	dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
	free(buffer);
	exit(99);
		}
	re = read(from, buffer, 1024);
	to = open(argv[2], O_WRONLY | O_APPEND);
} while (re > 0);

free(buffer);
close_file(from);
close_file(to);
return (0);
}
