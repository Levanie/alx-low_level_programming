#include "lists.h"

/**
 * insert_nodeint_at_index - function inserting new node at a given position
 * @head: pointer to a pointer to head of the list
 * @idx: index where the new node should be added, starting at 0
 * @n: value of the new node
 * Return: address of the new node, or NULL if failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *temp = *head;
	unsigned int i;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;

	if (!idx)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	for (i = 0; temp && i < idx - 1; i++)
		temp = temp->next;
	if (!temp)
	{
		free(new);
		return (NULL);
	}
	new->next = temp->next;
	temp->next = new;
	return (new);
}
