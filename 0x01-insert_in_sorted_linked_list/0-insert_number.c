#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: initial node
 * @number: number in the node
 * Return: new node or NULL.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp, *new;

	tmp = *head;
	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else if (tmp->n > new->n)
	{
		new->next = tmp;
		*head = new;
	}
	else
	{
		while (tmp->next && tmp->next->n < new->n)
			tmp = tmp->next;
		if (tmp->next == NULL)
			tmp->next = new;
		else
		{
			new->next = tmp->next;
			tmp->next = new;
		}
	}
	return (new);
}
