#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_trees.h"

int heap_sizer(heap_t *node);
heap_t *place_finder(heap_t *newnode);
heap_t *heap_sorter(heap_t **newnode);
bool tree_checker(heap_t *node);

/**
 * heap_insert - this function inserts a value into a Max Binary Heap
 * @root: a double pointer to the root node of the Heap
 * @value: the value store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newnode;

	newnode = binary_tree_node(place_finder(*root), value);

	if (newnode == NULL)
		return (NULL);

	if (place_finder(*root) == NULL)
	{
		*root = newnode;
	}
	else if (!(place_finder(*root)->left))
	{
		place_finder(*root)->left = newnode;
	}
	else
		place_finder(*root)->right = newnode;

	heap_sorter(&newnode);

	return (newnode);
}


/**
 * heap_sizer - gets size of heap
 * @node: pointer to first node
 *
 * Return: size of heap
 */
int heap_sizer(heap_t *node)
{
	size_t num;

	if (node == NULL)
		return (0);
	num = 1 + heap_sizer(node->left) + heap_sizer(node->right);
	return (num);
}


/**
 * place_finder - finds proper placement for new node
 * @newnode: pointer to root of tree
 *
 * Return: pointer to position at which to insert node
 */
heap_t *place_finder(heap_t *newnode)
{
	heap_t *temp;

	if (newnode == NULL)
		return (NULL);

	temp = newnode;
	if (!(heap_sizer(temp->left)) || !(heap_sizer(temp->right)))
		return (temp);
	if (!(tree_checker(temp->left)) || (tree_checker(temp->left) &&
					    tree_checker(temp->right) && heap_sizer(temp->left) ==
									  heap_sizer(temp->right)))
		return (place_finder(temp->left));
	else if (!(tree_checker(temp->right)) || (tree_checker(temp->left) &&
						  tree_checker(temp->right) &&
						  heap_sizer(temp->left) >
						   heap_sizer(temp->right)))
		return (place_finder(temp->right));

	return (temp);
}


/**
 * tree_checker - function that checks whether a tree is perfect
 * @node: a pointer to the root node
 *
 * Return: true is a tree is perfect, false otherwise
 */

bool tree_checker(heap_t *node)
{
	int lft;
	int rgt;

	if (node == NULL)
		return (false);

	lft = heap_sizer(node->left);
	rgt = heap_sizer(node->right);

	if (lft != rgt)
		return (false);
	return (true);
}


/**
 * heap_sorter - this function sorts the heap once a new node is inserted
 * @newnode: node inserted into heap
 *
 * Return: pointer to head of sorted heap
 */
heap_t *heap_sorter(heap_t **newnode)
{
	heap_t *curr;
	int temp;

	curr = *newnode;

	while (curr->parent != NULL)
	{
		if (curr->parent->n < curr->n)
		{
			temp = curr->parent->n;
			curr->parent->n = curr->n;
			curr->n = temp;
			*newnode = curr->parent;
		}
		curr = curr->parent;
	}
	return (curr);
}
