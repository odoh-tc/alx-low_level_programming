#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - elements
 * @h: ptr
 *
 * Return: num of the nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t x;

	for (x = 0; h != NULL; x++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (x);
}
