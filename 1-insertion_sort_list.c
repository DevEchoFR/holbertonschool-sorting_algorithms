#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	int i, j;
	int key;

	for (i = 1; i < list; i++)
	{
		key = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > key)
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}
