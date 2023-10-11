#include "shell.h"

/**
 * read_command - Read line from terminal
 *
 * Return: The input String
 */

char *read_command()
{
		char *buffer = NULL;
		size_t buf_size = 0;
		ssize_t bytesReadNo = 0;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		bytesReadNo = getline(&buffer, &buf_size, stdin);
		if (bytesReadNo == -1)
		{
			free(buffer), buffer = NULL;
			return (NULL);
		}
		return (buffer);
}
