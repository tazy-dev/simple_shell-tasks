#include "shell.h"

/**
 * shell - Custom simple shell
 *
 * @ac: Argument count
 * @av: Argument vector
 * Return: The Exit code
 */
int shell(int ac, char  **av)
{
	char *input = NULL;
	char **process = NULL;
	int status = 0, prompt_no = 0;
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
		prompt_no++;
		process = tokenize_command(input);
		if (!process)
			continue;
		if (_strcmp(process[0], "exit") == 0)
			exit_builtin(process, status);
		status = execute_command(process, av, prompt_no);

	}
	return (status);
}
