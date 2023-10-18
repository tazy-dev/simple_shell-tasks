#include "shell.h"
/**
 * exit_builtin - cause normal process termination
 *
 * @command: The Command passed to the shell
 * @av: The argument vector
 * @status: Pointer to the status variable
 * @prompt_num: Shell prompt number
 */
void exit_builtin(char **command, char **av, int *status, int prompt_num)
{
	int val = *status;

	if (command[1])
	{
		if (_is_pos_digit(command[1]))
			val = _atoi(command[1]);
		else
		{
			exit_error(av[0], command[1], prompt_num);
			free_command(command);
			*status = 2;
			return;
		}
	}

	free_command(command);
	exit(val);
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


