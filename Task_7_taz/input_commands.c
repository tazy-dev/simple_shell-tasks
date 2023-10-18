#include "shell.h"

/**
 * read_command - Read line from terminal
 * Return: The input String
 */

char *read_command()
{
	char *buffer = NULL;
	size_t buf_size = 0;
	ssize_t bytesReadNo = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	bytesReadNo = _getline(&buffer, &buf_size, stdin);
	if (bytesReadNo == -1)
	{
		free(buffer), buffer = NULL;
		return (NULL);
	}
	return (buffer);
}

/**
 * tokenize_command - Devide input string to a null
 *                      terminated non-zero strings.
 *
 * @ip: The input String
 * Return: A pointer to an array containing the splitted arhs
 */
char **tokenize_command(char *ip)
{
	char *token = NULL, *tmp = NULL;
	char **process = NULL;
	int counter = 0, index = 0;

	if (!ip)
	{
		return (NULL);
	}
	tmp = _strdup(ip);
	token = _strtok(tmp, DELIMITER);
	if (token == NULL)
	{
		free(ip), ip = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		counter++;
		token = _strtok(NULL, DELIMITER);
	}
	free(tmp), tmp = NULL;
	process = malloc(sizeof(char *) * (counter + 1));
	if (!process)
	{
		free(ip), ip = NULL;
		return (NULL);
	}
	token = _strtok(ip, DELIMITER);
	while (token)
	{
		process[index] = _strdup(token);
		token = _strtok(NULL, DELIMITER);
		index++;
	}
	free(ip), ip = NULL;
	process[index] = NULL;
	return (process);
}
