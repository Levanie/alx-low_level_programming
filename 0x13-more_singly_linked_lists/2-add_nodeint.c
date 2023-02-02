#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - function adding new node at the start of listint_t list
 *
 * @head: pointer to the pointer to the head of the list
 *
 * @n: integer data for the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{

	listint_t *new;

	new = malloc(sizeof(listint_t))
		if (new == NULL)
			return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
