#include "lists.h"

/**
 * get_dnodeint_at_index - node
 * @head: xd ptr
 * @index: node index
 *
 * Return: ptr
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int x;

	if (head == NULL)
		return (NULL);
	if (index == 0)
		return (head);
	for (x = 0; x < index; x++)
	{
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
