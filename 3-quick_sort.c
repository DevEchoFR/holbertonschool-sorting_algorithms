#include "sort.h"
void quick_sort_recursive(int *array, int low, int high, size_t size);
/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
/**
 * quick_sort_recursive - recursive function to perform quick sort
 * @array: pointer to the first element of the array
 * @low: starting index of the array partition
 * @high: ending index of the array partition
 * @size: size of the array
 * Return: void
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;
	int temp;

	if (low >= high)
		return;

	pivot = array[high];
	j = low;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			print_array(array, size);
			j++;
		}
	}
	temp = array[high];
	array[high] = array[j];
	array[j] = temp;
	quick_sort_recursive(array, low, j - 1, size);
	quick_sort_recursive(array, j + 1, high, size);
}
