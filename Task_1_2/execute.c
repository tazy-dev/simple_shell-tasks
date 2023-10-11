#include "shell.h"

/**
 * execute_command - Execute  the command passed using terminal
 *                      along with the designated flags.
 *
 * @command: The input command
 * @argv: The argument vector
 * Return: The exit code of the process
 */
int execute_command(char **command, char **argv)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);

	}
	else if (pid == 0)
	{

		if (execve(command[0], command, environ) == -1)
		{
			free_command(command);
			perror(argv[0]);
			exit(127);
		}

	}
	else
	{
		waitpid(pid, &status, 0);
		free_command(command);
	}

	return (WEXITSTATUS(status));

}
/**
 * free_command- Free memory allocated for storing command
 *                      and it's flags and arguments.
 *
 * @command: The array containnig the command-line.
 */
void free_command(char **command)
{
	int len = 0, i;

	while (command[len++])
		;
	for (i = 0; i < len; i++)
		free(command[i]);
	free(command);
}
