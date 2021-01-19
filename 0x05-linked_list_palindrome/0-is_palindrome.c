#include "lists.h"

/**
 * is_palindrome - checks if linked list is palindrome.
 * @head: head node
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	ssize_t buf[10000];
	size_t i, j;
	listint_t *tmp = NULL;

	tmp = *head;
	if (*head == NULL)
		return (1);
	i = 0;
	while (tmp != NULL)
	{
		buf[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	j = 0;
	i = i - 1;
	while (i > j)
	{
		if (buf[i--] != buf[j++])
			return (0);
	}
	return (1);
}
