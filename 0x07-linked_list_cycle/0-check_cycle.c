#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
 * check_cycle - this function checks to see if
 * a linked list contains a cycle
 * @list: pointer to the linked list
 *
 * Return: 1 if there's a cycle, and 0 otherwise
 *
 */
int check_cycle(listint_t *list)
{
	listint_t *frst = list;
	listint_t *scnd = list;


	if (list == NULL)
		return (0);

	if (list->next == NULL)
		return (0);

	while (frst != NULL && scnd != NULL && scnd->next != NULL &&
	       scnd->next->next != NULL)
	{
		frst = frst->next;
		scnd = scnd->next->next;

		if (scnd == frst)
			return (1);
	}
	return (0);
}
