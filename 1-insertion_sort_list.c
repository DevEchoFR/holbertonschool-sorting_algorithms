#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *node;
	listint_t *prev_node;
	listint_t *next_node;

	if (!list || !*list || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		node = current;
		while (node->prev && node->n < node->prev->n)
		{
			prev_node = node->prev;
			next_node = node->next;

			node->prev = prev_node->prev;
			node->next = prev_node;

			prev_node->prev = node;
			prev_node->next = next_node;

			if (node->prev)
				node->prev->next = node;
			else
				*list = node;

			if (next_node)
				next_node->prev = prev_node;

			if (node->prev)
				node = node->prev;
			else
				break;

			current = node->next;
		}
	}
}
