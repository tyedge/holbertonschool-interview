#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - This function builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *convert = NULL;
	int sizer = (int)size - 1;
	avl_t *tmp = NULL;

	if (array == NULL)
		return (NULL);

	tmp = builder(array, 0, sizer, &convert);
	if (tmp == NULL)
		return (NULL);
	return (convert);
}

/**
 * builder - builds new AVL Node
 * @arr: pointer to array to be cnoverted
 * @start: first index
 * @end: ending index
 * @aroot: root
 * Return: pointer to avl tree
 */
avl_t *builder(int *arr, int start, int end, avl_t **aroot)
{
	avl_t *newnode = NULL;
	avl_t *left = NULL;
	avl_t *right = NULL;
	int mid;

	if (start > end)
		return (NULL);

	mid = (end + start) / 2;

	builder(array, start, mid - 1, &left);
	builder(array, mid + 1, end, &right);

	newnode = malloc(sizeof(avl_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = array[mid];
	newnode->parent = NULL;
	newnode->left = left;
	newnode->right = right;

	if (left != NULL)
		left->parent = newnode;

	if (right != NULL)
		right->parent = newnode;

	*aroot = newnode;
	return (newnode);
}
