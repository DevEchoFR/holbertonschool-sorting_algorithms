#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *to_insert, *prev_node, *next_node;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		to_insert = current;
		current = current->next;

		while (to_insert->prev && to_insert->n < to_insert->prev->n)
		{
			prev_node = to_insert->prev;
			next_node = to_insert->next;


			to_insert->prev = prev_node->prev;
			to_insert->next = prev_node;

			prev_node->prev = to_insert;
			prev_node->next = next_node;

			if (to_insert->prev)
				to_insert->prev->next = to_insert;
			else
				*list = to_insert;

			if (next_node)
				next_node->prev = prev_node;

			print_list(*list);
		}
	}
}
