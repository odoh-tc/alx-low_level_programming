#include "main.h"

/**
 * _strlen - It finds the length of string
 * @str: A pointer to the string
 *
 * Return: length of string
 */
size_t _strlen(char *str)
{
	size_t y;

	for (y = 0; str[y]; y++)
		;
	return (y);
}

/**
 * append_text_to_file - It appends text at the end of a file.
 * @filename: filename
 * @text_content: NULL terminated string
 *
 * Return: success on 1 and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int c;
	ssize_t len;

	if (filename == NULL)
		return (-1);
	c  = open(filename, O_WRONLY | O_APPEND);
	if (c == -1)
		return (-1);
	if (text_content != NULL)
		len = write(c, text_content, _strlen(text_content));
	close(c);
	if (len == -1)
		return (-1);
	return (1);
}
