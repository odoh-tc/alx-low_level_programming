#include "lists.h"

/**
 * dlistint_len - nodes count
 * @h: d ptr
 *
 * Return: num of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t x;

	for (x = 0; h != NULL; x++)
		h = h->next;
	return (x);
}
