#include <stddef.h>
#include "lists.h"
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
/**
 * find_listint_loop - check description
 * Description: function that finds the loop in a linked list
 * @head: pointer
 * Return: address of node where loop starts or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	tortoise = hare = head;
	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;

		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;
			break;
		}
	}

	if (!tortoise || !hare || !hare->next)
		return (NULL);
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
	}
	return (hare);
}
