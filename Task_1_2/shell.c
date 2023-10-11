#include "shell.h"

/**
 * shell - Custom simple shell
 *
 * @ac: The Argument Count.
 * @av: The Argument Vector.
 * Return: The exit code -status- of the last command
 */
int shell(int ac, char  **av)
{
	char *input = NULL;
	char **process = NULL;
	int status = 0;
	(void) ac;

	while (1)
	{
		input = read_command();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		process = tokenize_command(input);
		if (!process)
			continue;

		status = execute_command(process, av);
	}
	return (status);
}

