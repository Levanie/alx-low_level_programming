#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - function that deletes the head node of listint_t list
 * and returns the head node's data (n)
 * @head: double pointer to head of the list
 * Return: data (n) of deleted head node or 0 if list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (!(*head))
		return (0);

	temp = *head;
	n = temp->n;
	*head = (*head)->next;
	free(temp);

	return (n);
}
