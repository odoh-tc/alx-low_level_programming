#include <stdio.h>
#include "main.h"

/**
 * create_array - creates an array of char
 * @size: size of array
 * @c: initial value
 *
 * Return: a pointer to the array, or NULL if it fails
 */

char *create_array(unsigned int size, char c);
{
	char *ptr;
	unsigned int i;

	if (size == 0)
		return (NULL);

	ptr = (char *)malloc(size * sizeof(char));

	for (i = 0; i < size; i++)
		ptr[i] = c;

	return (ptr);
}
