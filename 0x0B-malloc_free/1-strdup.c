#include <stdio.h>
#include "main.h"

/**
 * _strdup -  returns a pointer to a new string which is a duplicate of the string str
 * @str: string
 *
 * Return: returns a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	char *copy;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	copy = (char *)malloc((sizeof(char) * len) + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[len] = '\0';

	return (copy);
}
