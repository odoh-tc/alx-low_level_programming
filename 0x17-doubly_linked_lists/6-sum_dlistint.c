#include "lists.h"

/**
 * sum_dlistint - it all sums
 * @head: d ptr
 *
 * Return: sum
 */
int sum_dlistint(dlistint_t *head)
{
	int q = 0;

	while (head != NULL)
	{
		q += head->n;
		head = head->next;
	}
	return (q);
}
