#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - node add
 * @head: ptr
 * @n: d value
 *
 * Return: d ptr to new
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *y;

	if (head == NULL)
		return (NULL);
	y = malloc(sizeof(dlistint_t));
	if (y == NULL)
		return (NULL);
	y->n = n;
	y->prev = NULL;
	y->next = *head;
	*head = y;
	if (y->next != NULL)
		(y->next)->prev = y;
	return (y);
}
