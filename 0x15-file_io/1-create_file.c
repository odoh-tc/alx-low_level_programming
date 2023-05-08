#include "main.h"
/**
 * create_file -creates and initializes char of array
 *
 * @text_content: NULL terminated string
 * @filename: filename
 *
 * Return: success on 1, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int x, y, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	x = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	y = write(x, text_content, len);

	if (x == -1 || y == -1)
		return (-1);

	close(x);

	return (1);
}
