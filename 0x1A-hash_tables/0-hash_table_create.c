#include "hash_tables.h"

/**
 * hash_table_create -  hash table.
 * @size: The size
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *th;
	unsigned long int i;

	th = malloc(sizeof(hash_table_t));
	if (th == NULL)
		return (NULL);

	th->size = size;
	th->array = malloc(sizeof(hash_node_t *) * size);
	if (th->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		th->array[i] = NULL;

	return (th);
}
