#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - Check description
 * Description: function that converts a binary number to an unsigned int
 * @b: Pointer
 * Return: the converted number, or 0 if
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (b == NULL)
		return (0);
	for (; *b; b++)
	{
		if (*b != '0' && *b != '1')
			return (0);
		n = (n << 1) + (*b - '0');
	}
	return (n);
}
