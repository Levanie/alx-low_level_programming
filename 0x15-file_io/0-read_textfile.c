#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads and prints a file to the standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 on failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;

	ssize_t n_read, n_written;

	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(*buf) * letters);
	if (!buf)
	{
		close(fd);
		return (0);
	}
	n_read = read(fd, buf, letters);
	if (n_read == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	n_written = write(STDOUT_FILENO, buf, n_read);
	if (n_written == -1 || n_written != n_read)
	{
		free(buf);
		close(fd);
		return (0);
	}
	free(buf);
	close(fd);
	return (n_written);
}
