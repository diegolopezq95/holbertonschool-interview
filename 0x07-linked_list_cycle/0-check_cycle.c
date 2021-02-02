#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: linked list to check
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *tmp, *tmp2;

	if (list == NULL)
		return (0);
	tmp = list;
	tmp2 = list;
	while (tmp->next != NULL && tmp2->next != NULL && tmp2->next->next != NULL)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next->next;
		if (tmp == tmp2)
			return (1);
	}
	return (0);
}
