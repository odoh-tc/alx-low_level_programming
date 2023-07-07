#include "hash_tables.h"

/**
 * hash_table_get - retrieves value associatd with a key
 * @ht: table too retrieve value from
 * @key: key to ffind value
 *
 * Return: value aassociated with key, or NULL if key cannot be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *mp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	mp = ht->array[index];
	while (mp != NULL)
	{
		if (strcmp(mp->key, key) == 0)
			return (mp->value);
		mp = mp->next;
	}
	return (NULL);
}
