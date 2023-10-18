#include "shell.h"
/**
 * exit_builtin - cause normal process termination
 *
 * @command: The Command passed to the shell
 * @status: The exit status
 */
void exit_builtin(char **command, int status)
{
	free_command(command);
	exit(status);
}
/**
 * env_builtin - prints the current enviroment
 *
 */
void env_builtin(void)
{
	while (*environ)
	{
		write(1, *environ, _strlen(*environ));
		write(1, "\n", 1);
		environ++;
	}

}


