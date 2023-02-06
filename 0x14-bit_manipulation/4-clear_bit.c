#include "main.h"
#include <stdio.h>
#include <stddef.h>

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to number to clear the bit in
 * @index: index, starting from 0 of the bit to clear
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (!n || index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n &= ~(1UL << index);
	return (1);
}
