#include "hash_tables.h"

/**
 * hash_table_delete - deeletes a hassh table
 * @ht: hash table to deletee
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int y;
	hash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (y = 0; y < ht->size; y++)
	{
		while (ht->array[y] != NULL)
		{
			next = ht->array[y]->next;
			free(ht->array[y]->key);
			free(ht->array[y]->value);
			free(ht->array[y]);
			ht->array[y] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	free(ht);
}
