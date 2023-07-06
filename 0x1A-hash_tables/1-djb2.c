#include "hash_tables.h"

/**
 * hash_djb2 - Hash implementing  djb2 algorithm.
 * @str: de string.
 *
 * Return: cal hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int y;

	hash = 5381;
	while ((y = *str++))
		hash = ((hash << 5) + hash) + y; /* hsh * 33 + c */

	return (hash);
}
