#include "shell.h"

/**
 * execute_command - Execute  the command passed using terminal
 *                      along with the designated flags.
 *
 * @command: The input command
 * @argv: The argument vector
 * @prompt_number: The number of prompts done by the shell
 * Return: The exit code of the process
 */
int execute_command(char **command, char **argv, int prompt_number)
{
	char *command_found = NULL;
	int status;
	pid_t pid;

	command_found = check_command_in_path(command[0]);
	if (!command_found)
	{
		_perror(argv[0], command[0], prompt_number);
		free_command(command);
		return (127);
	}
	if (_strlen(command_found) != _strlen(command[0]))
		command[0] = expand_command(command[0], command_found,
		_strlen(command_found));
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

/**
 * get_env_var - get enviroment varible
 *
 * @key: The Enviroment varible key
 * Return: The Enviroment varible value
 */
char *get_env_var(char *key)
{

	char *token = NULL, *result = NULL, *env_var = NULL;
	int index = 0;

	if (!key)
		return (NULL);
	while (environ[index])
	{
		env_var = _strdup(environ[index]);
		token = strtok(env_var, "=");
		if (_strcmp(key, token) == 0)
		{
			token = strtok(NULL, "\n");
			result = _strdup(token);
			free(env_var);
			return (result);
		}
		free(env_var), env_var = NULL;
		index++;
	}
	return (NULL);
}
/**
 * check_command_in_path - Check if the given command exist
 *
 * @command: The INput Command
 * Return: The command full path
 */
char *check_command_in_path(char *command)
{

	char *absolute_path = NULL, *current_path = NULL, *path;
	struct stat st;

	if (_strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (command);
		else
			return (NULL);
	}
	path = get_env_var("PATH");
	if (!path)
		return (NULL);
	current_path = strtok(path, ":");
	while (current_path)
	{
		absolute_path = malloc(_strlen(current_path) + _strlen(command) + 2);
		if (!absolute_path)
			return (NULL);
		_strcpy(absolute_path, current_path);
		_strcat(absolute_path, "/");
		_strcat(absolute_path, command);
		if (stat(absolute_path, &st) == 0)
		{
			free(path), path = NULL;
			return (absolute_path);
		}

		free(absolute_path), absolute_path = NULL;
		current_path = strtok(NULL, ":");
	}
	free(path), path = NULL;
	return (NULL);
}
