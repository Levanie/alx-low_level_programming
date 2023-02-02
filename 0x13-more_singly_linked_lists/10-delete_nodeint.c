#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes node at a specific index in a linked list
 * @head: Pointer to a pointer to the head of the linked list
 * @index: Index of the node to delete, starting at 0
 * Return: 1 on success, -1 on failure
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *node_to_delete;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	temp = *head;
	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}
	for (i = 0; temp != NULL && i < index - 1; i++)
		temp = temp->next;
	if (temp == NULL || temp->next == NULL)
		return (-1);

	node_to_delete = temp->next;
	temp->next = node_to_delete->next;
	free(node_to_delete);
	return (1);
}
