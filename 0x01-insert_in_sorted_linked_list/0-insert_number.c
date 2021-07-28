#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - this function inserts an integer into a sorted singly linked
 * list
 * @head: double pointer to head of linked list
 * @number: number to be inserted into list
 *
 * Return: address of the newly inserted node, else NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *nude = NULL;
	listint_t *oldie;

	nude = malloc(sizeof(listint_t));
	if (nude == NULL)
		return (NULL);

	nude->n = number;

	if (*head == NULL || (*head)->n >= nude->n)
	{
		nude->next = *head;
		*head = nude;
	}
	else
	{
		oldie = *head;
		while (oldie->next != NULL && oldie->next->n < nude->n)
		{
			oldie = oldie->next;
		}
		nude->next = oldie->next;
		oldie->next = nude;
	}
	return (nude);
}
