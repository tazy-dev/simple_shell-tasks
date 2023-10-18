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
 *			and stops if '\n' is encoutered
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

/**
 * _strtok - Splits input string to tokens according to
 *					the delimeteres
 * @str: string to tokenize
 * @delim: list of delimeters
 *
 * Return: The resultant token
 */
char *_strtok(char *str, const char *delim)
{
	static char *buffer;
	static int i;
	int idx = 0;

	if (str == NULL && buffer == NULL)
		return (NULL);
	if (str == NULL && buffer[i] == '\0')
	{
		free(buffer);
		i = 0;
		return (NULL);
	}
	if (str != NULL)
	{
		i = 0;
		buffer = _strdup(str);
	}
	else
		str = malloc(_strlen(buffer));
	while (buffer[i] != '\0')
	{
		if (_strchr2(delim, buffer[i]) != 0)
			break;
		str[idx] = buffer[i];
		i++;
		idx++;
	}
	str[idx] = '\0';
	i++;
	while (buffer[i] != '\0')
	{
		if (_strchr2(delim, buffer[i]) == 0)
			break;
		i++;
	}
	return (str);
}
/**
 * _strchr2 - locates a character in a string
 * @s: string to search
 * @c: char to find
 *
 * Return: a pointer to the first occurrence of the character
 * c in the string s, or NULL if the character is not found
 */
int _strchr2(const char *s, int c)
{
	while (1)
	{
		if (*s == c)
			return (1);
		else if (*s == '\0')
			return (0);
		s++;
	}
}
