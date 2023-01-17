#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name:name
 * @age:age
 * @owner:owner
 * Return: NULL if function fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	int i, n, m;
	dog_t *newer;

	for (i = 0; name[i] != '\0'; i++)
		;
	for (n = 0; owner[n] != '\0'; n++)
		;
	newer = malloc(sizeof(dog_t));
	if (newer == NULL)
	{
		free(newer);
		return (NULL);
	}
	newer->name = malloc(i * sizeof(newer->name));
	if (newer->name == NULL)
	{
		free(newer->name);
		free(newer);
		return (NULL);
	}
	for (m = 0; m <= i; m++)
	{
		(*newer).name[m] = name[m];
	}
	(*newer).age = age;
	newer->owner = malloc(n * sizeof(newer->owner));
	if (newer->owner == NULL)
	{
		free(newer->name);
		free(newer->owner);
		free(newer);
		return (NULL);
	}
	for (m = 0; m <= n; m++)
	{
		newer->owner[m] = owner[m];
	}

	return (newer);
}
