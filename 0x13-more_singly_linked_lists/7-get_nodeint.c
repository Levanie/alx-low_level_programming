#include "lists.h"

/**
 * get_nodeint_at_index - function that returns nth node of a listint_t list
 * @head: pointer to head of the list
 * @index: index of the node to return, starting at 0
 * Return: nth node of the list or NULL if node does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; head && i < index; i++)
		head = head->next;

	return (head ? head : NULL);
}
