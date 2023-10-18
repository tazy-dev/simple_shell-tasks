#include "shell.h"
/**
 * *_strchr - locates a character in a string
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
