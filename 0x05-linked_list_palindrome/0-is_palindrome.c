#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * is_palindrome - checks if a singly linked list is a
 * palindrome
 * @head: pointer to a pointer of the first element of the list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 *
 */

int is_palindrome(listint_t **head)
{
	listint_t *num = *head;
	listint_t *path = *head;
	int buffer[2048];
	int count = 0, len, i = 0, start = 0, end;


	if (head == NULL)
		return (0);

	if (*head == NULL)
		return (1);

	while (num != NULL)
	{
		count++;
		num = num->next;
	}
	len = count;
	end = len - 1;

	if (len == 1)
		return (1);
	while (path != NULL)
	{
		buffer[i] = path->n;
		path = path->next;
		i++;
	}
	buffer[i++] = '\0';
	while (start < len && end >= 0)
	{
		if (start > end)
			return (1);
		if (buffer[start] != buffer[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}
