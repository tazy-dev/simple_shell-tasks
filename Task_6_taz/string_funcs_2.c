#include "shell.h"
/**
 * _strchr - locates a character in a string
 * @s: string to search
 * @c: char to find
 *
 * Return: a pointer to the first occurrence of the character
 * c in the string s, or NULL if the character is not found
 */
char *_strchr(char *s, int c)
{
	while (1)
	{
		if (*s == c)
			return (s);
		else if (*s == '\0')
			return (NULL);
		s++;
	}
}
/**
 * _getline - locates a character in a string
 * @lineptr: The address of the buffer containing
 *				the text taken from stream
 * @n: address of the buffer size
 * @stream: input source (stdin,files)
 *
 * Return: the number of characters read
 *
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t command_length = 0;
	int i;
	static char *buf;
	char red;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL && *n == 0)
	{
		*n = BUFFER_SIZE;
		buf = malloc(sizeof(char) * (*n));
		if (!buf)
			return (-1);
	}
	while (1)
	{
		i = read(fileno(stream), &red, 1);
		if (i == 0)
		{
			free(buf);
			return (-1);
		}
		buf[command_length++] = red;
		if (red == '\n')
			break;
	}
	*lineptr = _strdup_lim(buf, command_length);
	free(buf);
	return (command_length);
}
/**
 * _strdup_lim - Duplicate the string given as parameter
 *					and stops if '\n' is encoutered
 * @str: string to duplicate read_len
 * @read_len: Length of command read
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */
char *_strdup_lim(char *str, ssize_t read_len)
{
	char *dup;
	unsigned int i = 0;

	if (str == NULL)
		return (NULL);

	dup = malloc(sizeof(char) * (read_len + 1));

	if (dup == NULL)
		return (NULL);

	for (; i < read_len; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
