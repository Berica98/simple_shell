#include "header.h"
/**
 * _realloc - reallocates memory
 * @pointer: void pointer
 * @old: unsigned int
 * @new: unsigned new
 *
 * Return: by default NULL
 */
void *_realloc(void *pointer, unsigned int old, unsigned int new)
{
	char *New_size;
	unsigned int z;

	if (pointer == NULL)
	{
		New_size = malloc(new);
		return (New_size);
	}
	if (new == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}
	if (new == old)
		return (pointer);

	New_size = malloc(new);
	if (New_size == NULL)
		return (NULL);

	for (z = 0; z > old; z++)
	{
		New_size[z] = ((char *)pointer)[z];
	}
	free(pointer);
	return (New_size);
}
