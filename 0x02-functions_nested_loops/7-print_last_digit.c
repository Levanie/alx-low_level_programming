#include "main.h"

/**
 * print_last_digit - print last digit of integer
 * @n: integer argument
 * Return: last digit of number
 */

int print_last_digit(int n)
{
int ld = n % 10;

if (ld < 0)
ld *= -1;

_putchar(ld + '0');

return (0);
}
