#include "hash_tables.h"

/**
 * make_hash_node - new hash node
 * @key: key for node
 * @value: for node
 *
 * Return: the new node
 */
hash_node_t *make_hash_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}


/**
 * hash_table_set - sets a key to value in hash table
 * @ht: hash table to add elementt to
 * @key: key for  data
 * @value: data to store
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *hash_node, *mp;
	char *new_value;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	mp = ht->array[index];
	while (mp != NULL)
	{
		if (strcmp(mp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(mp->value);
			mp->value = new_value;
			return (1);
		}
		mp = mp->next;
	}
	hash_node = make_hash_node(key, value);
	if (hash_node == NULL)
		return (0);
	hash_node->next = ht->array[index];
	ht->array[index] = hash_node;
	return (1);
}
