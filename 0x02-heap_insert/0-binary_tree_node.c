#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: parent node.
 * @value: value of the node.
 * Return: node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *new;

	tmp = parent;
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	if (parent == NULL)
	{
		new->n = value;
		tmp = new;
		tmp->left = NULL;
		tmp->right = NULL;
		return (tmp);
	}
	else
	{
		new->parent = tmp;
		new->n = value;
		new->left = NULL;
		new->right = NULL;
		if (tmp->n > value)
			tmp->left = new;
		else
			tmp->right = new;
		return (new);
	}
}
