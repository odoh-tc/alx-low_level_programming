#include "hash_tables.h"

/**
 * hash_table_print - prints a hsh table
 * @ht: hash table to pprint
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int y;
	hash_node_t *tmp;
	char flag = 0; /* 0 while no ddata has been printed yet */

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	for (y = 0; y < ht->size; y++)
	{
		tmp = ht->array[y];
		while (tmp != NULL)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			flag = 1;
			tmp = tmp->next;
		}
	}
	printf("}\n");
}
