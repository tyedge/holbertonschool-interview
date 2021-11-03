#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: pointer on the first node where value is located, or NULL if
 * value is not present in list
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *expr, *prev;

	if (!list)
		return (NULL);

	expr = list->express;
	prev = list;
	printf("Value checked at index [%lu] = [%d]\n", expr->index, expr->n);

	while (expr && expr->n < value)
	{
		prev = expr;
		expr = expr->express;

		if (!expr)
		{
			expr = prev;
			while (expr->next)
				expr = expr->next;
			break;
		}
		printf("Value checked at index [%lu] = [%d]\n", expr->index,
		       expr->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
	       expr->index);

	while (prev && expr->n >= prev->n)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index,
		       prev->n);

		if (prev->n == value)
			return (prev);

		prev = prev->next;
	}
	return (NULL);
}
