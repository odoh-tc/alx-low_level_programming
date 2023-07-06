#ifndef _HASH_TABLES_H_
#define _HASH_TABLES_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);

/**
 * struct hash_node_s - Node of  hsh table
 *
 * @key: The key, string
 * @value: The value corresponding to key
 * @next: A pointer to next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hsh table data structure
 *
 * @size: The size of array
 * @array: An array of size @size
 * Each cell of thiss array is a pointer to first node of a linked list,
 * because we want our HashTable to use Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is uniquee in the HashTable
 * @value: The value to a key
 * @next: A pointer to next node of the List
 * @sprev: A pointer to previous element of the sorted linked list
 * @snext: A pointer to next element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hsh table data structure
 *
 * @size: The size of array
 * @array: An array of size @size
 * Each cell of this arrayy iss a pointer to the ffirst node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to first element of the soorted linked list
 * @stail: A pointer to last element of the sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;
