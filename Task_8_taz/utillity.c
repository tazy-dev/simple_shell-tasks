#include "shell.h"

/**
 * *expand_command - Replace the command with it's full path
 * @ptr: pointer to the memory previsouly allocated by for the command
 * @new_path: The command full path
 * @new_size: length of the complete path
 *
 * Return: pointer to the newly allocated memory block
 */
char *expand_command(char *ptr, char *new_path, size_t new_size)
{
	char *ptr1;
	size_t i;

	free(ptr), ptr = NULL;
	ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);
	for (i = 0; i < new_size; i++)
		ptr1[i] = new_path[i];
	free(new_path), new_path = NULL;
	return (ptr1);
}

/**
 * _perror - Prints an error msg to stdout for envalid or not found command
 *
 * @prog: The name of the running program
 * @command: The input command
 * @shell_prompt_number: the number of commands passed to the shell until now
 *
 * Return: pointer to the newly allocated memory block
 */
void _perror(char *prog, char *command, int shell_prompt_number)
{
	char *error_msg = "not found\n";

	write(STDERR_FILENO, prog, _strlen(prog));
	write(STDERR_FILENO, ": ", 2);
	print_number(shell_prompt_number);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, _strlen(error_msg));
}
/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
	unsigned int num = n;
	char digit;

	if ((num / 10) > 0)
		print_number(num / 10);
	digit = (num % 10) + '0';
	write(STDERR_FILENO, &digit, 1);
}
/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}
/**
 * exit_error - Prints an error msg to stdout for envalid or not found command
 * @prog: The name of the running program
 * @command: The input command
 * @shell_prompt_number: the number of commands passed to the shell until now
 *
 * Return: pointer to the newly allocated memory block
 */
void exit_error(char *prog, char *command, int shell_prompt_number)
{
	char *error_msg = "exit: Illegal number: ";

	write(STDERR_FILENO, prog, _strlen(prog));
	write(STDERR_FILENO, ": ", 2);
	print_number(shell_prompt_number);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, _strlen(error_msg));
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, "\n", 1);
}
