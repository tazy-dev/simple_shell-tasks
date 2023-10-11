#include "shell.h"

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
			return (NULL);
		tmp = strdup(ip);
		token = strtok(tmp, DELIMITER);
		if (token == NULL)
		{
			free(ip), ip = NULL;
			free(tmp), tmp = NULL;
			return (NULL);
		}
		while (token)
		{
			counter++;
			token = strtok(NULL, DELIMITER);
		}
		free(tmp), tmp = NULL;
		process = malloc(sizeof(char *) * (counter + 1));
		if (!process)
		{
			free(ip);
			return (NULL);
		}
		token = strtok(ip, DELIMITER);
		while (token)
		{
			process[index] = strdup(token);
			token = strtok(NULL, DELIMITER), index++;
		}
		free(ip), ip = NULL;
		process[index] = NULL;
		return (process);
}
