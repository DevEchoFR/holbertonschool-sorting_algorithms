#include "sort.h"
/**
 * selection_sort - sorts an array of integers
 * in ascending order using the selection sort algorithm
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int swap;
	int min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap = array[i];
			array[i] = array[min_idx];
			array[min_idx] = swap;
			print_array(array, size);
		}
	}
}
