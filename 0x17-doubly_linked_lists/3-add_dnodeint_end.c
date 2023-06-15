#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - node add
 * @head: ptr
 * @n: new
 *
 * Return: ptr to new
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *y, *tmp;

	if (head == NULL)
		return (NULL);
	y = malloc(sizeof(dlistint_t));
	if (y == NULL)
		return (NULL);
	y->n = n;
	y->next = NULL;
	if (*head == NULL)
	{
		y->prev = NULL;
		*head = y;
		return (y);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = y;
	y->prev = tmp;
	return (y);
}
