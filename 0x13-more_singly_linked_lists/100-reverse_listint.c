#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint - function that reverses a listint_t linked list
 * @head: input
 * Return:  a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}
